#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "testsForStack.h"

Element* push(Element* head, char value){
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

char peek(Element* head){
    if (head == NULL){
        return '0';
    }
    return head->value; //���������� �������� ��������� head ���� ���� �� ������
}

void show(Element* head){
    Element* current = head;
    while (current != NULL){
        printf("%c\n", current->value);
        current = current->next;
    }
    printf("\n");
}
