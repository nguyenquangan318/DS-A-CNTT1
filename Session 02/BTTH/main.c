#include <stdio.h>
#include <stdlib.h>

int *insertToArray(int *numbers, int *size, int value);

void printArray(int *numbers, int size);

int *deleteFromArray(int *numbers, int *size, int deletePos);

int main(void) {
    int choice;
    int *numbers = NULL;
    int size = 0;
    do {
        printf("\tMENU\n");
        printf("1. Them phan tu\n");
        printf("2. Hien thi\n");
        printf("3. Xoa phan tu\n");
        printf("4. Thoat\n");
        printf("Nhap lua chon : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                numbers = insertToArray(numbers, &size, 1);
                numbers = insertToArray(numbers, &size, 2);
                numbers = insertToArray(numbers, &size, 3);
                numbers = insertToArray(numbers, &size, 4);
                break;
            case 2:
                printArray(numbers, size);
                break;
            case 3:
                numbers = deleteFromArray(numbers, &size, 1);
                break;
            case 4:
                break;
            default:
                printf("Lua chon khong hop le");
        }
    } while (choice != 4);
    return 0;
}

int *insertToArray(int *numbers, int *size, int value) {
    //B1: Cap phat lai bo nho cho mang
    numbers = (int *) realloc(numbers, (*size + 1) * sizeof(int));
    //B2: Gan lai gia tri cho phan tu cuoi cung
    numbers[*size] = value;
    //B3: Tang gia tri cua size len 1
    (*size)++;
    //B3: Tra ve mang moi (con tro moi duoc cap phat)
    return numbers;
}

void printArray(int *numbers, int size) {
    for (int i = 0; i < size; i++) {
        printf("numbers[%d] = %d ", i, numbers[i]);
    }
    printf("\n");
}

int *deleteFromArray(int *numbers, int *size, int deletePos) {
    //B1: Kiem tra vi tri muon xoa
    if (deletePos< 0 || deletePos > (*size - 1)) {
        printf("Vi tri xoa khong hop le\n");
        return numbers;
    }
    //B2: Dich cac phan tu phia sau phan tu muon xoa ve phia truoc 1
    for (int i = deletePos; i < (*size - 1); i++) {
        numbers[i] = numbers[i + 1];
    }
    //B3: Cap phat lai bo nho cho mang
    numbers = (int *) realloc(numbers, (*size - 1) * sizeof(int));
    //B4: Giam kich co mang
    (*size)--;
    //B5: Tra ve mang moi duoc cap phat
    return numbers;
}
