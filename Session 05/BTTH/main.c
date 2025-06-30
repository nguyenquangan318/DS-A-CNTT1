#include <stdio.h>

//Tim kiem nhi phan de quy
int binarySearchRecursion(int arr[], int low, int high, int key) {
    //Xay dung dieu kien dung
    if (low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == key) {
        return mid;
    }else if (key > arr[mid]) {
        //Thuc hien bai toan con o nua sau
        binarySearchRecursion(arr, mid +1, high, key);
    }else {
        //Thuc hien bai toan con o nua truoc
        binarySearchRecursion(arr, low, mid-1, key);
    }
}

int main(void) {
    printf("Hello, World!\n");
    return 0;
}