#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "testsForStack.h"

Element* push(Element* head, int value){
    Element* element = malloc(sizeof(Element)); //�������� ������ ��� ������ �������
    element->value = value; //����� � �������� ������ ������� �������� ������ ����� ��������
    element->next = head; //��������� ��������� ���������� �������� �� ��� ������� ��� ������ ��
    return element; //���������� ��������� �� ����� ��������� ������
}

Element* pop(Element* head){
    if (head == NULL){
        return head;
    }
    Element* elementNext = head->next; // ���� head ����, �� ���� ��������� ����� ������ ���� �������
    free(head);
    return elementNext;

}

int peek(Element* head){
    if (head == NULL){
        return -1;
    }
    return head->value; //���������� �������� ��������� head ���� ���� �� ������
}

void show(Element* head){
    Element* current = head;
    while (current != NULL){
        printf("%d\n", current->value);
        current = current->next;
    }
    printf("\n");
}

int sizeStack(Element * head) {
    Element * current = head;
    int size = 0;
    while (current != NULL) {
        ++size;
        current = current->next;
    }
    return size;
}
