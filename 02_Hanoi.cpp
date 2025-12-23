#include <stdio.h>

void hanoi(int n, char a, char b, char c) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", a, c);
        return;
    }
    
    hanoi(n - 1, a, c, b);
    printf("Move disk %d from %c to %c\n", n, a, c);
    hanoi(n - 1, b, a, c);
}

int main() {
    int n = 3; 
    
    hanoi(n, 'A', 'B', 'C');
    
    return 0;
}