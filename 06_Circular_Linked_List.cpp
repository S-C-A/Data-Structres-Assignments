#include <stdio.h>
#include <stdlib.h>

struct n {
    int d;
    struct n *next;
};

struct n *h = NULL;

void add_mid(int v, int pos) {
    struct n *t = (struct n*)malloc(sizeof(struct n));
    t->d = v;
    
    if (h == NULL) {
        h = t;
        t->next = h;
        return;
    }

    struct n *temp = h;
    for (int i = 0; i < pos - 1; i++) {
        temp = temp->next;
    }
    t->next = temp->next;
    temp->next = t;
}

void del(int v) {
    if (h == NULL) return;

    struct n *curr = h, *prev;
    
    if (h->d == v) {
        if (h->next == h) {
            free(h);
            h = NULL;
            return;
        }
        struct n *last = h;
        while (last->next != h) last = last->next;
        last->next = h->next;
        struct n *tmp = h;
        h = h->next;
        free(tmp);
        return;
    }

    prev = h;
    curr = h->next;
    while (curr != h) {
        if (curr->d == v) {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void print() {
    if (h == NULL) return;
    struct n *t = h;
    do {
        printf("%d -> ", t->d);
        t = t->next;
    } while (t != h);
    printf("(head)\n");
}

int main() {
    add_mid(10, 0);
    add_mid(20, 1);
    add_mid(30, 2);
    add_mid(15, 1); 

    printf("List: ");
    print();

    del(20);
    printf("After deleting 20: ");
    print();

    return 0;
}