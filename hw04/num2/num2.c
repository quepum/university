#include <stdio.h>
#include <stdbool.h>
#include "sort.h"

#define SIZE 100


int mostFrequentElement(int array[], int length) {
    int mostFrequent = array[0];
    int count = 1;
    int maxCount = 1;

    for (int i = 1; i < length - 1; ++i) {
        if (array[i] == array[i - 1]) {
            ++count;
            if (count > maxCount) {
                maxCount = count;
                mostFrequent = array[i];
            }
        } else {
            count = 1;
        }
    }
    return mostFrequent;
}

bool test1() {
    int test1[10] = {1, 2, 1, 2, 2, 1, 1, 2, 1, 1};
    return mostFrequentElement(test1, 10) == 1;
}

bool test2() {
    int test2[10] = {1};
    return mostFrequentElement(test2, 10) == 1;
}

bool test3() {
    int test3[1] = {1};
    return mostFrequentElement(test3, 10) == 1;
}

int main(){
    if (!(tests() && test1() && test2() && test3())){
        printf("Tests failed, something went wrong");
        return 1;
    } else {
        printf("%s", "The tests were passed successfully\n");
    }

    FILE* inputCollection = fopen("inputData.txt", "r");
    if (inputCollection == NULL){
        printf("File doesn't exist");
        return -1;
    }


    fclose(inputCollection);
    return 0;
}