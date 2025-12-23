#include <stdio.h>

int g[10][10];
int v[10];     
int n = 6;     

void dfs(int s) {
    v[s] = 1;
    printf("%d ", s);
    for (int i = 0; i < n; i++) {
        if (g[s][i] == 1 && !v[i]) {
            dfs(i);
        }
    }
}

int main() {
    int i, j;
    
    for(i=0; i<10; i++) 
        for(j=0; j<10; j++) g[i][j] = 0;

    g[0][1] = g[1][0] = 1;
    g[1][2] = g[2][1] = 1;
    
    g[3][4] = g[4][3] = 1;

    int count = 0;
    for (i = 0; i < n; i++) {
        if (!v[i]) {
            count++;
            printf("Cluster %d: ", count);
            dfs(i);
            printf("\n");
        }
    }

    return 0;
}