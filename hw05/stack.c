#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

Element *push(Element *head, char value) {
    Element *element = malloc(sizeof(Element)); //�������� ������ ��� ������ �������
    assert(element != NULL);
    element->value = value; //����� � �������� ������ ������� �������� ������ ����� ��������
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

char peek(Element *head) {
    if (head == NULL) {
        return '0';
    }
    return head->value; //���������� �������� ��������� head ���� ���� �� ������
}

void show(Element *head) {
    Element *current = head;
    while (current != NULL) {
        printf("%c ", current->value);
        current = current->next;
    }
    printf("\n");
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
