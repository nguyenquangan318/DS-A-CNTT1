#include <stdio.h>
#include <stdlib.h>

int checkDup(int numbers[], int size);
int checkDupSubArray(int numbers[], int size);

int main(void) {
    return 0;
}

int checkDup(int numbers[], int size) {
    //B1: xet tung phan tu trong mang
    for (int i = 0; i < size; i++) {
        //B2: Dem phan tu dang duoc xet di so sanh voi tat ca cac phan tu con lai
        for (int j = i+1; j < size; j++) {
            //B2.1: Neu trung thi ket thuc ham va tra ve gia tri 1
            if (numbers[i] == numbers[j]) {
                return 1;
            }
        }
    }
    //B2.2: Neu duyet het mang ma khong co trung lap thi tra ve gia tri 0
    return 0;
}

int checkDupSubArray(int numbers[], int size) {
    //B1: Tạo ra mảng phụ chứa số lượng phan tu bang voi gioi
    //han do lon của mang dươc xet
    int seenNumbers[1001] = {0};
    //B2: Duyet qua tung phan tu trong mang ban dau
    for (int i = 0; i < size; i++) {
        //B3: Neu phan duoc xet da co phan tu tuong ung trong mang phu la 1
        //thi tra ve gia tri 1
        if (seenNumbers[numbers[i]] == 1) {
            return 1;
        }
        //B4: Ung voi phan tu duoc xet thi tang gia tri cua phan tu tuong
        //ung trong mang phu len 1
        seenNumbers[numbers[i]] = 1;
    }
    //B5: Neu duyet het mang ma khong co phan tu nao bi trung thi tra
    //ve gia tri 0
    return 0;
}