#include <stdio.h>

// //Bai 1
void loop(int n) {
    if (n==0) {
        return;
    }
    loop(n-1);
    printf("%d\n", n);
}

//Bai 2
int total(int n) {
    if (n==1) {
        return 1;
    }
    return n+total(n-1);

}

//Bai 3
int factorial(int n) {
    if (n < 1) return 1;
    return n*factorial(n-1);
}

//Bai 4
int sumNumber(int a, int b) {
    if (b<a) {
        return 0;
    }
    return b + sumNumber(a, b-1);
}

//Bai 6
int sumRevcursive(int arr[], int size , int index) {
    if (index < 0) {
        return 0;
    }
    return arr[index] + sumRevcursive(arr,size,index - 1);
}


//Bai 7
int fibonacci(int k) {
    if (k==0 ) return 0;
    if (k==1)return 1;
    return fibonacci(k-1)+fibonacci(k-2);
}


//Bai 9
int countPath(row, col) {
    //Neu di den vien tren hoac vien trai
    if (row < 0 || col < 0) return 1;
    // tinh toan so duong di den o ben tren va o ben trai
    return countPath(row, col-1) + countPath(row-1, col);
}

int main(void) {
    int n;
    printf("nhap vao so luong so fibonacci can in :");
    scanf("%d",&n);

    int fib[n];
    for (int i = 1; i < n; i++) {
        fib[i]=fibonacci(i);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ",fib[i]);
    }
}