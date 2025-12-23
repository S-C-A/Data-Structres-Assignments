#include <stdio.h>

int h[100];
int s = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insert(int v) {
    s++;
    int i = s;
    h[i] = v;
    
    while (i > 1 && h[i/2] < h[i]) {
        swap(&h[i/2], &h[i]);
        i = i/2;
    }
}

void print() {
    for (int i = 1; i <= s; i++) {
        printf("%d ", h[i]);
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(5);
    insert(30);
    insert(15);

    printf("Max Heap: ");
    print();

    return 0;
}