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
void searchTelephoneByName(const char name[], int numLines, Entry collection[]){
    for (int i = 0; i < numLines; ++i){
        if (strcmp(collection[i].name, name) == 0){
            printf("%s\n", collection[i].number);
        }
    }
    printf("������ ����� ��� � �����������\n");

}
//����� ��� �� ��������
void searchNameByTelephone(){

}
//��������� ����
void save(){

}

void printCommands(){
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
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                printf("����� ������� �� ����������, ������� ����� �����\n");
        }
    } while (command !=0);

    return 0;
}