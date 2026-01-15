#include <stdio.h> 
// Tower of Hanoi program using Recursion 
void toh(int n, char towerA, char towerC, char towerB) 
{ 
    if (n == 1) 
    { 
        printf("\n Move disk 1 from tower %c to tower %c",towerA ,towerC ); 
        return; 
    } 
    toh(n-1, towerA, towerB, towerC); 
    printf("\n Move disk %d from tower %c to tower %c", n, towerA, towerC); 
    toh(n-1, towerB, towerC,towerA); 
} 
 
int main() 
{ 
    int n ; 
    printf("Enter number of disks: "); 
    scanf("%d", &n); 
    toh(n, 'A','C','B'); // toh(no of disks,from,to,using auxiliary tower) 
    return 0; 
}
