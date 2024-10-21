#include <stdio.h>
#define SIZE (sizeof(int) * 8)

void fromDecimalToBinary(int num, int array[]){
    int bit = 1;
    for (int i = SIZE - 1; i >= 0; i--) {
        array[i] = ((num & bit) ? 1 : 0);
        num >>= 1;
    }
}

int fromBinaryToDecimal(const int binNum[]) {
    int currentExponent = 1;
    int result = 0;
    for (int i = SIZE - 1; i >= 0; i--) {
        result += binNum[i] * currentExponent;
        currentExponent *= 2;
    }
    return result;
}

void printer(int array[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
}

int main(){
    int number1 = 0;
    int number2 = 0;

    printf("%s", "������� ��� �����:\n");
    scanf("%d%d", &number1, &number2);

    int binNumber1[SIZE] = { 0 };
    int binNumber2[SIZE] = { 0 };
    int result[SIZE] = { 0 };

    fromDecimalToBinary(number1, binNumber1);
    fromDecimalToBinary(number2, binNumber2);

    printf("����� %d � �������� �������������:\n", number1);
    printer(binNumber1);
    printf("����� %d � �������� �������������:\n", number2);
    printer(binNumber2);

    number1 = fromBinaryToDecimal(binNumber1);
    number2 = fromBinaryToDecimal(binNumber2);

    printf("(%d) + (%d) = %d", number1, number2, number1 + number2);
    return 0;
}
