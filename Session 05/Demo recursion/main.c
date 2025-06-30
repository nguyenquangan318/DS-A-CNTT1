#include <stdio.h>

//In cac so tu 1 - n
void print1ToN(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d\n", i);
    }
}

void print1ToNRecursion(int n, int i) {
    if (i>n) {
        return;
    }
    printf("%d\n", i);
    print1ToNRecursion(n, i+1);
}

int main(void) {
    print1ToNRecursion(5, 1);
    return 0;
}
