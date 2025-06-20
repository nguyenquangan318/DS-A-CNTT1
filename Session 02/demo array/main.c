#include <stdio.h>
#include <stdlib.h>

int main(void) {
    //mang tinh
    // int numbers[10]={1,2,3};
    //mang dong
    int *numbers = (int*)malloc(10 * sizeof(int));
    // int *numbersCalloc = (int*)calloc(10, sizeof(int));
    for (int i = 0; i < 10; i++) {
        numbers[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }
    //Cap phat lai bo nho cho mang dong
    numbers=(int*)realloc(numbers, sizeof(int)*5);
    return 0;
}
