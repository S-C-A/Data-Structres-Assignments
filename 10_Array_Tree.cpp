#include <stdio.h>

int tree[50];
int n = 0;

void insert(int v) {
    n++;
    tree[n] = v;
}

void get_children(int i) {
    if (i > n || tree[i] == -1) {
        printf("Node not found\n");
        return;
    }
    
    printf("Node: %d\n", tree[i]);
    
    if (2 * i <= n)
        printf("Left child: %d\n", tree[2 * i]);
    else
        printf("Left child: None\n");
        
    if (2 * i + 1 <= n)
        printf("Right child: %d\n", tree[2 * i + 1]);
    else
        printf("Right child: None\n");
}

int main() {
    // Manually creating a tree
    insert(10); // Root (index 1)
    insert(20); // Left of 10
    insert(30); // Right of 10
    insert(40); // Left of 20
    insert(50); // Right of 20

    int idx = 1; 
    get_children(idx);
    
    printf("\nChecking node 2:\n");
    get_children(2);

    return 0;
}