#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "stack.h"
#include "testsForStack.h"

const int length = 101;

int rangOfOperand(const char operand) {
    int rang = 0;
    switch (operand) {
        case '(':
            rang = 1;
            break;
        case '+':
        case '-':
            rang = 2;
            break;
        case '*':
        case '/':
            rang = 3;
            break;
        default:
            break;
    }
    return rang;
}

Element *fromInfixToPostfix(const char expression[]) {
    Element *draftVersion = NULL;
    Element *auxiliary = NULL;
    int size = (int) strlen(expression);

    for (int i = 0; i < size; ++i) {
        if (expression[i] != ' ' || expression[i] != '\n') {
            switch (expression[i]) {
                case '+':
                case '-':
                case '*':
                case '/': {
                    int rangCurrentOperand = rangOfOperand(expression[i]);
                    while (rangOfOperand(peek(auxiliary)) > rangCurrentOperand) {
                        draftVersion = push(draftVersion, peek(auxiliary));
                        auxiliary = pop(auxiliary);
                    }
                    auxiliary = push(auxiliary, expression[i]);
                    break;
                }
                case '(':
                    auxiliary = push(auxiliary, expression[i]);
                    break;
                case ')':
                    while (peek(auxiliary) != '(') {
                        draftVersion = push(draftVersion, peek(auxiliary));
                        auxiliary = pop(auxiliary);
                    }
                    auxiliary = pop(auxiliary);
                    break;
                default:
                    if (expression[i] != ' ') {
                        draftVersion = push(draftVersion, expression[i]);
                    }
                    break;
            }
        }
    }
    while (!isEmpty(auxiliary)) {
        draftVersion = push(draftVersion, peek(auxiliary));
        auxiliary = pop(auxiliary);
    }

    Element *answer = NULL;
    while (!isEmpty(draftVersion)) {
        answer = push(answer, peek(draftVersion));
        draftVersion = pop(draftVersion);
    }
    return answer;
}

bool test() {
    char *test = "(1 + 1) * 2 - (9 / 3)";
    char *correctAnswer = "11+2*93/-";
    Element *result = fromInfixToPostfix(test);
    int i = 0;
    while (result != NULL) {
        if (result->value != correctAnswer[i]) {
            return false;
        }
        result = result->next;
        ++i;
    }
    return true;
}

int main() {
    if (!(test() && stackTests())) {
        printf("Tests failed, something went wrong");
        return -1;
    }
    printf("%s", "Tests were passed successfully\n");

    char *expression = malloc(sizeof(char) * length);
    if (expression == NULL) {
        printf("ERROR: out of memory");
        return -1;
    }

    printf("Enter a mathematical expression in infix form\n");
    scanf("%[^\n]", expression);

    Element *result = fromInfixToPostfix(expression);
    printf("Postfix form is\n");
    show(result);

    free(expression);
    return 0;
}