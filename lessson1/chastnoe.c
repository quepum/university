#include <stdio.h>
#include <math.h>

int func(int num1, int num2) {
    int result = 0, divisible = fabs(num1), divisor = fabs(num2);
    while (divisible >= divisor) {
        divisible -= divisor;
        ++result;
    }
    if ((num1 > 0 && num2 > 0) || (num1 < 0 && num2 < 0)) {
        return result;
    } else {
        return -result;
    }
}

int main(void) {
    int a, b;
    printf("Введите делимое и делитель\n");
    scanf("%d %d", &a, &b);
    if (b == 0) {
        printf("%s", "error");
    } else {
        printf("Неполное частное равно %d", func(a, b));
    }
    return 0;
}
