#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    //B1: Tạo ra 2 mảng con bên trái và bên phải
    int leftArrIndex, rightArrIndex, arrIndex;
    //Kích cỡ mảng con trái
    int leftArrSize = mid - left + 1;
    //Kích cỡ mảng con phải
    int rightArrSize = right - mid;
    int leftArr[leftArrSize], rightArr[rightArrSize];
    //B2: Sao chép giá trị từ mảng cha vào 2 mảng con
    for (leftArrIndex = 0; leftArrIndex < leftArrSize; leftArrIndex++) {
        leftArr[leftArrIndex] = arr[left + leftArrIndex];
    }
    for (rightArrIndex = 0; rightArrIndex < rightArrSize; rightArrIndex++) {
        rightArr[rightArrIndex] = arr[mid + 1 + rightArrIndex];
    }
    //B3: Trộn 2 mảng con lại trong mảng cha
    leftArrIndex = 0, rightArrIndex = 0, arrIndex = left;
    while (leftArrIndex < leftArrSize && rightArrIndex < rightArrSize) {
        if (leftArr[leftArrIndex] <= rightArr[rightArrIndex]) {
            arr[arrIndex] = leftArr[leftArrIndex];
            leftArrIndex++;
        }else {
            arr[arrIndex] = rightArr[rightArrIndex];
            rightArrIndex++;
        }
        arrIndex++;
    }
    while (leftArrIndex < leftArrSize) {
        arr[arrIndex] = leftArr[leftArrIndex];
        leftArrIndex++;
        arrIndex++;
    }
    while (rightArrIndex < rightArrSize) {
        arr[arrIndex] = rightArr[rightArrIndex];
        rightArrIndex++;
        arrIndex++;
    }
}

void mergeSort(int arr[], int left, int right) {
    //Điều kiện dừng
    if (left == right) {
        return;
    }
    int mid = (left+right)/2;
    //Bài toán con với phần bên trái
    mergeSort(arr, left, mid);
    //Bài toán con với phần bên phải
    mergeSort(arr, mid+1, right);
    //Trộn 2 mảng con lại
    merge(arr, left, mid, right);
}

int main(void) {
    return 0;
}