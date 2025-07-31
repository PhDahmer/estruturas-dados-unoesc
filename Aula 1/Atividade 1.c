#include <stdio.h>

void printvint(int a[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(void)
{
    int a[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    int n;
    scanf("%d", &n);
    printvint(a, n);
    return 0;
}