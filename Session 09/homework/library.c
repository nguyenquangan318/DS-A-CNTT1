#include "library.h"

#include <stdio.h>
//Xay dung ham phan vung
int partition(int arr[], int left, int right) {
    //B1: Chon phan tu cuoi cung lam pivot
    int pivot = arr[right];
    //Khoi tao bien luu tru vi tri can chen pivot = left - 1
    int i = left-1;
    //Su dung vong lap de tien hanh tim vi tri dung cua pivot
    for (int j = left; j <= right-1; j++) {
        if (arr[j] <= pivot) {
            i++;
            //Doi cho phan tu voi phan tu o vi tri can chen
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //doi cho pivot voi phan tu nam o vi tri can chen
    int temp = arr[i+1];
    arr[i+1] = arr[right];
    arr[right] = temp;
    //Tra ve vi tri dung cua pivot
    return i+1;
}

//Xay dung ham de quy su dung thuat toan quick sort
void quickSort(int arr[], int left, int right) {
    //Dieu kien dung co it hon 1 phan tu
    if (left < right) {
        //B2: Thuc hien phan vung mang can duoc sap xep
        int pivotPos = partition(arr, left, right);
        //B3: Goi lai ham voi phan ben trai pivot
        quickSort(arr, left, pivotPos - 1);
        //B4: Goi lai ham voi phan ben phai pivot
        quickSort(arr, pivotPos + 1, right);
    }

}

void hello(void) {
}