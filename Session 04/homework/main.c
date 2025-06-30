#include <stdio.h>

int main(void) {
    //Nhap vao so hang va so cot cua mang 2 chieu
    int row, col;
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of cols: ");
    scanf("%d", &col);
    if (row <= 0 || col <= 0 || row >= 1000 || col >= 1000) {
        printf("Invalid input\n");
        return 1;
    }
    //Nhap vao tung phan tu trong mang
    int matrix[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("matri[%d][%d] = ", row, col);
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("matrix[%d][%d] = %d\n", i, j, matrix[i][j]);
        }
    }
    //nhap vao so hang can tinh tong
    int k;
    printf("Nhap so hang: ");
    scanf("%d", &k);
    if (k < 0 || k > row) {
        printf("Invalid input\n");
    }
    int sum = 0;
    for (int i = 0; i < col; i++) {
        sum += matrix[k][i];
    }
    //In ra tong cua hang da duoc nhap vao
    printf("Tong hang thu %d la : %d", k, sum);
    return 0;
}
