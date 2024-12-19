#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Element *push(Element *head, int value) {
    Element *element = malloc(sizeof(Element)); //�������� ������ ��� ������ �������
    element->value = value; //����� � �������� ������ ������� �������� ������� ����� ��������
    element->next = head; //��������� ��������� ���������� �������� �� ��� ������� ��� ������ ��
    return element; //���������� ��������� �� ����� ��������� ������
}

Element *pop(Element *head) {
    if (head == NULL) {
        return head;
    }
    Element *elementNext = head->next; // ���� head ����, �� ���� ��������� ����� ������ ���� �������
    free(head);
    return elementNext;
}

int peek(Element *head) {
    if (head == NULL) {
        return -1;
    }
    return head->value; //���������� �������� ��������� head ���� ���� �� ������
}

int sizeStack(Element *head) {
    Element *current = head;
    int size = 0;
    while (current != NULL) {
        ++size;
        current = current->next;
    }
    return size;
}

bool isEmpty(Element *head) {
    return head == NULL;
}

void removeStack(Element **head) {
    Element *current = *head;
    Element *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}
