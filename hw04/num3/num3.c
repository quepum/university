#include <stdio.h>
#include <string.h>

#define SIZE 100

typedef struct Entry {
    char name[SIZE];
    char number[SIZE];
} Entry;

//������ �������
int readEntries(const char* fileName, Entry collection[]){
    FILE *file;
    int numLines = 0;
    file = fopen("C:\\CLionProjects\\RepoGit1\\hw04\\num3\\dataBase.txt", "r");
    char name[SIZE];
    char phoneNumber[SIZE];
    while(fscanf(file, "%s", name) != EOF && fscanf(file, "%s", phoneNumber) != EOF) {
        strcpy(collection[numLines].name, name);
        strcpy(collection[numLines].number, phoneNumber);
        ++numLines;
    }
    fclose(file);
    return numLines;
}

// ������� �������� ������
void addEntry(){
}

//����������� ��� ������
void displayContent(int numLines, Entry collection[]){
    printf("���������� ����������� �����������\n");
    for (int i = 0; i < numLines; ++i){
        printf("%s %s\n", collection[i].name, collection[i].number);
    }
    printf("�����\n");
}
//����� ������� �� �����
int searchTelephoneByName(const char name[], const int numLines, const Entry collection[]){
    for (int i = 0; i < numLines; ++i){
        if (strcmp(collection[i].name, name) == 0){
            return i;
        }
    }
    return -1;

}

//����� ��� �� ��������
int searchNameByTelephone(const char phoneNumber[], const int numLines, const Entry collection[]){
    for (int i = 0; i < numLines; ++i){
        if (strcmp(collection[i].number, phoneNumber) == 0){
            return i;
        }
    }
    return -1;

}
//��������� ����
void save(){

}

void printCommands(void){
    printf("���������� ����������\n");
    printf("0 - �����\n"
           "1 - �������� ������ (��� � �������)\n"
           "2 - ����������� ��� ��������� ������\n"
           "3 - ����� ������� �� �����\n"
           "4 - ����� ��� �� ��������\n"
           "5 - ��������� ������� ������ � ����\n");
    printf("������� ����� �������\n");
}

int main(void){
    int command = 0;
    printCommands();
    Entry collection[SIZE];
    int numberOfLines = readEntries("dataBase.txt", collection);
    do{
        scanf("%d", &command);
        switch (command) {
            case 0:
                break;
            case 1:
                break;
            case 2:
                displayContent(numberOfLines, collection);
                break;
            case 3:
                printf("������� ��� ��������:\n");
                char name[SIZE] = {'\0'};
                scanf("%s", name);
                int resultOfSearchingByName = searchTelephoneByName(name, numberOfLines, collection);
                if (resultOfSearchingByName != -1){
                    printf("%s\n", collection[resultOfSearchingByName].number);
                    break;
                } else{
                    printf("������ ����� ��� � ���������� �����������\n");
                    break;
                }
            case 4:
                printf("������� ����� �������� ��������:\n");
                char phoneNumber[SIZE] = {'\0'};
                scanf("%s", phoneNumber);
                int resultOfSearchingByPhone = searchNameByTelephone(phoneNumber, numberOfLines, collection);
                if (resultOfSearchingByPhone != -1){
                    printf("%s\n", collection[resultOfSearchingByPhone].name);
                } else{
                    printf("������ ������ ��� � ���������� �����������\n");
                }
                break;
            case 5:
                break;
            default:
                printf("����� ������� �� ����������, ������� ����� �����\n");
                break;
        }
    } while (command !=0);

    return 0;
}