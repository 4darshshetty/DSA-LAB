#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int coef;
    int xexp, yexp, zexp;
    struct node *link;
};

typedef struct node *polynomial;
polynomial head = NULL;
int n = 5;
int i;

polynomial createNode();
polynomial createPoly();
void peval(int x, int y, int z);

int main() {
    int ch;
    while (1) {
        printf("\n1.Evaluate Polynomial\n2.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                peval(1, 2, 3);
                break;
            case 2:
                exit(0);
        }
    }
}

polynomial createNode() {
    polynomial temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter coef and exponents of x, y, z: ");
    scanf("%d%d%d%d", &temp->coef, &temp->xexp, &temp->yexp, &temp->zexp);
    temp->link = NULL;
    return temp;
}

polynomial createPoly() {
    polynomial temp, last;
    if (head == NULL) {
        temp = createNode();
        head = temp;
    }
    last = head;
    for (i = 1; i < n; i++) {
        temp = createNode();
        last->link = temp;
        last = last->link;
    }
    last->link = head;
    return head;
}

void peval(int x, int y, int z) {
    polynomial p = createPoly();
    long sum = 0;
    for (i = 0; i < n; i++) {
        printf("%dx^%dy^%dz^%d", p->coef, p->xexp, p->yexp, p->zexp);
        if (i != n - 1)
            printf("+");
        sum = sum + (p->coef) * pow(x, p->xexp) * pow(y, p->yexp) * pow(z, p->zexp);
        p = p->link;
    }
    printf("\nResult=%ld\n", sum);
}
