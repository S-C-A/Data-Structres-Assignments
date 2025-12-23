#include <stdio.h>

int main() {
    int a[4][4] = {
        {0, 0, 0, 5},
        {0, 1, 0, 0},
        {2, 0, 0, 0},
        {0, 0, 0, 7}
    };

    int i, j;
    int b[50][3]; 
    int k = 1;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (a[i][j] != 0) {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
    }

    b[0][0] = 4;
    b[0][1] = 4;
    b[0][2] = k - 1;

    printf("Row Col Val\n");
    for (i = 0; i < k; i++) {
        printf("%d %d %d\n", b[i][0], b[i][1], b[i][2]);
    }

    return 0;
}