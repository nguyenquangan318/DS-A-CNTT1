#include <stdio.h>

void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    //Xay dung dieu kien dung khi khong con dia nao nua
    //So dia bang 0
    if (n == 0) {
        return;
    }
    //Giai quyet bai toan con dua n - 1 dia tu tru bat dau sang tru trung gian
    towerOfHanoi(n-1, fromRod, auxRod, toRod);
    //Dua dia lon nhat sang tru dich
    printf("Di chuyen dia %d di tu tru %c sang tru %c",n, fromRod, toRod);
    //Giai quyet bai toan con dua n - 1 dia sang tru dich tu tru trung gian
    towerOfHanoi(n-1, auxRod, toRod, fromRod);
}

int main(void) {
    printf("Hello, World!\n");
    return 0;
}