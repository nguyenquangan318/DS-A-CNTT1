#include <stdio.h>

//Nguyen mau ham
int linearSearch(int array[], int size, int value);
int binarySearch(int array[], int size, int value);

int main(void) {
    //Khai bao va gan gia tri cho mang du lieu
    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //Goi ham tim kiem
    return 0;
}

//trien khai ham
int linearSearch(int array[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}
int binarySearch(int array[], int size, int value) {
    //B1: So sanh phan tu o giua mang voi gia tri can tim kiem
    int low = 0, high = size - 1;
    while (low <= high) {
        //B2: Neu trung thi tra ve gia tri va ket thuc tim kiem
        int mid = (low + high) / 2;
        if (array[mid] == value) {
            return mid;
        }else if (array[mid] < value) {
            //B3: Neu nho hon thi thuc hien tim kiem nua sau
            low = mid + 1;
        }else {
            //B4: Neu lon hon thi thuc hien tim kiem nua truoc
            high = mid - 1;
        }
    }
    //B5: Neu khong tim thay thi tra ve -1
    return -1;
}