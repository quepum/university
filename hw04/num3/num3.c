#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 100
#define TESTSIZE 5

typedef struct Entry {
    char name[SIZE];
    char number[SIZE];
} Entry;

//������ �������
int readEntries(const char *fileName, Entry collection[]) {
    FILE *file;
    int numLines = 0;
    file = fopen(fileName, "a+");
    char name[SIZE];
    char phoneNumber[SIZE];
    while (fscanf(file, "%s", name) != EOF && fscanf(file, "%s", phoneNumber) != EOF) {
        strcpy(collection[numLines].name, name);
        strcpy(collection[numLines].number, phoneNumber);
        ++numLines;
    }
    fclose(file);
    return numLines;
}

// ������� �������� ������
int addEntry(const char newName[], const char newPhoneNumber[], int *numLines, Entry collection[]) {
    if (*numLines < SIZE) {
        Entry newEntry = {{'\0'},
                          {'\0'}};
        strcpy(newEntry.name, newName);
        strcpy(newEntry.number, newPhoneNumber);
        collection[*numLines] = newEntry;
        ++(*numLines);
        return 0;
    }
    return -1;
}

//����������� ��� ������
void displayContent(const int numLines, Entry collection[]) {
    printf("���������� ����������� �����������\n");
    for (int i = 0; i < numLines; ++i) {
        printf("%s %s\n", collection[i].name, collection[i].number);
    }
    printf("�����\n");
}

//����� ������� �� �����
int searchTelephoneByName(const char name[], const int numLines, Entry collection[]) {
    for (int i = 0; i < numLines; ++i) {
        if (strcmp(collection[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

//����� ��� �� ��������
int searchNameByTelephone(const char phoneNumber[], const int numLines, Entry collection[]) {
    for (int i = 0; i < numLines; ++i) {
        if (strcmp(collection[i].number, phoneNumber) == 0) {
            return i;
        }
    }
    return -1;
}

//��������� ����
void saveChanges(const char *fileName, const int numLines, Entry collection[]) {
    FILE *file;
    file = fopen(fileName, "w");
    for (int i = 0; i < numLines; ++i) {
        fprintf(file, "%s %s\n", collection[i].name, collection[i].number);
    }
    printf("��������� ������� ���������\n");
    fclose(file);
}

void printCommands(void) {
    printf("���������� ����������\n");
    printf("0 - �����\n"
           "1 - �������� ������ (��� � �������)\n"
           "2 - ����������� ��� ��������� ������\n"
           "3 - ����� ������� �� �����\n"
           "4 - ����� ��� �� ��������\n"
           "5 - ��������� ������� ������ � ����\n");
    printf("������� ����� �������\n");
}

bool testsOfSearchingByName() {
    Entry testingCollection1[TESTSIZE] = {{"Elena", "12345"},
                                          {"James", "098764"},
                                          {"Egor",  "234135"},
                                          {"Ann",   "234211"},
                                          {"Mary",  "2131314577"}};
    if (searchTelephoneByName("Mary", TESTSIZE, testingCollection1) == -1) {
        return false;
    }
    Entry testingCollection2[TESTSIZE] = {{"Elena", "12345"},
                                          {"James", "098764"},
                                          {"Egor",  "234135"},
                                          {"Ann",   "234211"},
                                          {"Mary",  "2131314577"}};
    if (searchTelephoneByName("Alina", TESTSIZE, testingCollection2) != -1) {
        return false;
    }

    Entry testingCollection3[TESTSIZE] = {};
    if (searchTelephoneByName("Mary", TESTSIZE, testingCollection3) != -1) {
        return false;
    }
    return true;
}

bool testsOfSearchingByTelephone() {
    Entry testingCollection1[TESTSIZE] = {{"Elena", "12345"},
                                          {"James", "098764"},
                                          {"Egor",  "234135"},
                                          {"Ann",   "234211"},
                                          {"Mary",  "2131314577"}};
    if (searchNameByTelephone("234211", TESTSIZE, testingCollection1) == -1) {
        return false;
    }
    Entry testingCollection2[TESTSIZE] = {{"Elena", "12345"},
                                          {"James", "098764"},
                                          {"Egor",  "234135"},
                                          {"Ann",   "234211"},
                                          {"Mary",  "2131314577"}};
    if (searchNameByTelephone("66666", TESTSIZE, testingCollection2) != -1) {
        return false;
    }
    Entry testingCollection3[TESTSIZE] = {};
    if (searchNameByTelephone("9898989898", TESTSIZE, testingCollection3) != -1) {
        return false;
    }
    return true;
}

bool testOfAddingEntry() {
    Entry testingCollection[TESTSIZE] = {};
    int numLines = 0;
    char newName[SIZE] = "Lexus";
    char newPhone[SIZE] = "77777";
    addEntry(newName, newPhone, &numLines, testingCollection);
    if (strcmp(testingCollection[0].name, newName) != 0 || strcmp(testingCollection[0].number, newPhone) != 0) {
        return false;
    }
    return true;
}

int main(void) {
    if (!(testsOfSearchingByName() && testsOfSearchingByTelephone() && testOfAddingEntry())) {
        printf("����� �� ��������, ���-�� ����� �� ���\n");
        return 1;
    } else {
        printf("%s", "��������� ������� ������ ��� �����\n");
    }

    int command = 0;
    printCommands();
    Entry collection[SIZE];
    int numberOfLines = readEntries("dataBase.txt", collection);
    do {
        scanf("%d", &command);
        switch (command) {
            case 0:
                break;
            case 1:
                printf("������� ��� �������� ��� ������\n");
                char nameForAdding[SIZE] = {'\0'};
                scanf("%s", nameForAdding);
                printf("������� ����� �������� �������� %s ��� ������\n", nameForAdding);
                char numberForAdding[SIZE] = {'\0'};
                scanf("%s", numberForAdding);
                if (addEntry(nameForAdding, numberForAdding, &numberOfLines, collection) == 0) {
                    printf("�������, �� �������� ��������� ���������\n");
                } else {
                    printf("����� ��� ������ ���������, � ����������� ����� ��������� �� ����� 100 �������\n");
                }
                break;
            case 2:
                displayContent(numberOfLines, collection);
                break;
            case 3:
                printf("������� ��� ��������:\n");
                char name[SIZE] = {'\0'};
                scanf("%s", name);
                int resultOfSearchingByName = searchTelephoneByName(name, numberOfLines, collection);
                if (resultOfSearchingByName != -1) {
                    printf("%s\n", collection[resultOfSearchingByName].number);
                } else {
                    printf("������ ����� ��� � ���������� �����������\n");
                }
                break;
            case 4:
                printf("������� ����� �������� ��������:\n");
                char phoneNumber[SIZE] = {'\0'};
                scanf("%s", phoneNumber);
                int resultOfSearchingByPhone = searchNameByTelephone(phoneNumber, numberOfLines, collection);
                if (resultOfSearchingByPhone != -1) {
                    printf("%s\n", collection[resultOfSearchingByPhone].name);
                } else {
                    printf("������ ������ ��� � ���������� �����������\n");
                }
                break;
            case 5:
                saveChanges("dataBase.txt", numberOfLines, collection);
                break;
            default:
                printf("������� � ����� ������� �� ����������\n");
        }
    } while (command <= 5 && command > 0);
    return 0;
}