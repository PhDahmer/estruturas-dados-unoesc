#include <stdio.h>
#include <stdlib.h>

int cmpvint(int a1[], int a2[], int n){
    for (int i = 0; i <= n; i++) {
        if (a1[i] != a2[i]) {
            return 0; 
        }
    }
    return 1; 
}

int main(void)
{
    int a1[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    int a2[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    int n;
    scanf("%d", &n);
    
    if (cmpvint(a1, a2, n)) {
        puts("Os vetores sao iguais.\n");
    } else {
        puts("Os vetores sao diferentes.\n");
    }
    
    return 0;
}