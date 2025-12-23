#include <stdio.h>

int g[10][10];
int v[10];
int n;

void dfs(int s) {
    int i;
    v[s] = 1;
    printf("%d ", s);
    
    for (i = 0; i < n; i++) {
        if (g[s][i] == 1 && !v[i]) {
            dfs(i);
        }
    }
}

int main() {
    int i, j;
    n = 4;

    for(i=0; i<n; i++)
        for(j=0; j<n; j++) g[i][j] = 0;

    g[0][1] = g[1][0] = 1;
    g[0][2] = g[2][0] = 1;
    g[1][3] = g[3][1] = 1;  

    printf("DFS Result: ");
    dfs(0);
    printf("\n");

    return 0;
}