#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
struct node // structure for each term of polynomial 
{ 
    int coef;             // coeficient 
    int xexp, yexp, zexp; // x,y,z exponents... 
    struct node *link;    // self referential structure.. 
}; 
typedef struct node *polynomial; 
polynomial head = NULL, p1, p2, p3; // Create a header node.. 
polynomial createNode();            // Create node for each term 
polynomial createPoly();      // Create a polynomial by adding nodes end 
void peval(int x, int y, int z); // Polynomial evaluation by passing x,y,z variables 
polynomial padd(polynomial, polynomial); 
int i, n = 5; // Number of terms in a given polynomial 
int main() 
{ 
    int ch; 
    while (1) 
    { 
       printf("\n1.Evaluate Polynomial \n 2.Exit\n Enter your choice:"); 
        scanf("%d", &ch); 
        switch (ch) 
        { 
        case 1: 
            peval(1, 2, 3); // pass x=1,y=2,z=3 to evaluate polynomial. 
            break; 
        case 2: 
            exit(0); 
        } 
    } 
} 
/* Function to create node as a term of polynomial */ 
polynomial createNode() // Create node for each term of polynomial 
{ 
    int i; 
    polynomial temp; 
    temp = malloc(sizeof(struct node));  // Allocate memory for new node 
    // Read coef and exponents 
printf("\nEnter coef and exponents of x,y,z:");  
    scanf("%d%d%d%d", &temp->coef, &temp->xexp,&temp->yexp,&temp->zexp); 
    temp->link = NULL; 
    return temp; 
} 
/* Function to create Polynomial */ 
polynomial createPoly() 
{ 
    polynomial temp, last; 
    if (head == NULL) // If no nodes in list temp is first node 
    { 
        temp = createNode(); // create temp node 
        head = temp;         // temp is first node i.e header node 
    } 
    last = head;            // Take last as reference to insert at end 
    for (i = 1; i < n; i++) // insert n=5 nodes at end of list  
    { 
        temp = createNode(); // create a new node 
        last->link = temp;   // attach end of the list 
        last = last->link;   // move to last node 
    } 
    last->link = head; // last node link point to head make the list Circular 
    return head; 
} 
/* Function to evaluate Polynomial */ 
void peval(int x, int y, int z) 
{ 
    polynomial p = createPoly(); // create a polynomial for the given data 
    long sum = 0;                // Evaluate polynomial and store in sum 
    for (i = 0; i < n; i++) 
    { 
        printf("%dx^%dy^%dz^%d", p->coef, p->xexp, p->yexp, p->zexp); 
 
        if (i != 4)  //  avoid printing last + after polynomial  
            printf("+"); 
 
        // Evaluate polynomial by calculating each term 
        sum = sum + (p->coef)*pow(x, p->xexp)*pow(y, p->yexp)* 
              pow(z, p->zexp); 
         
        p = p->link; // Move to next term or node of polynomial 
    } 
    printf("\n Result=%ld\n", sum); // Print the result... 
} 