#include <stdio.h>

int main() {
    int a[100] = {10, 20, 30, 40, 50};
    int n = 5; 
    int i, pos, v;

    v = 25;   
    pos = 2; 

    for (i = n - 1; i >= pos; i--) {
        a[i + 1] = a[i];
    }
    a[pos] = v;
    n++;

    printf("After adding: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    pos = 1; 

    for (i = pos; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;

    printf("After deleting: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}