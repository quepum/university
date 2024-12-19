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

char pop(Element **head) {
    if (*head == NULL) {
        return 0;
    }
    char element = (*head)->value;
    Element *newElement = (*head)->next;
    free(*head);
    (*head) = newElement;
    return element;
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
