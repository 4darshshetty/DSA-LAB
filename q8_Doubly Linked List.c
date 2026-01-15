#include <stdio.h>
#include <stdlib.h>

struct Employee{
    struct Employee *llink;
    int ssn;
    char name[50];
    char dept[20];
    char designation[20];
    float sal;
    char phno[10];
    struct Employee *rlink;
};

typedef struct Employee *NODE;

int count = 0;
NODE first = NULL;

NODE createNode();
void createDll();
void insertFront();
void insertEnd();
void deleteFront();
void deleteEnd();
void displayDll();

int main()
{
    int ch;
    while (1)
    {
        printf("\n1.Create Emp DLL\n2.Insert Front\n3.Insert End\n4.Delete Front\n5.Delete End\n6.Display DLL\n7.Exit\nEnter Your Choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: createDll(); break;
            case 2: insertFront(); break;
            case 3: insertEnd(); break;
            case 4: deleteFront(); break;
            case 5: deleteEnd(); break;
            case 6: displayDll(); break;
            case 7: exit(0);
        }
    }
    return 0;
}

NODE createNode()
{
    NODE temp;
    temp = malloc(sizeof(struct Employee));
    printf("Enter emp SSN: ");
    scanf("%d", &temp->ssn);
    printf("Enter emp Name: ");
    scanf("%s", temp->name);
    printf("Enter emp Designation: ");
    scanf("%s", temp->designation);
    printf("Enter emp Department: ");
    scanf("%s", temp->dept);
    printf("Enter emp Salary: ");
    scanf("%f", &temp->sal);
    printf("Enter emp Phone Number: ");
    scanf("%s", temp->phno);
    temp->llink = NULL;
    temp->rlink = NULL;
    count++;
    return temp;
}

void createDll()
{
    NODE temp, cur;
    temp = createNode();
    if(first == NULL)
    {
        first = temp;
    }
    else
    {
        cur = first;
        while(cur->rlink != NULL)
            cur = cur->rlink;
        cur->rlink = temp;
        temp->llink = cur;
    }
    displayDll();
}

void insertFront()
{
    NODE temp;
    temp = createNode();
    if(first != NULL)
    {
        first->llink = temp;
        temp->rlink = first;
    }
    first = temp;
    displayDll();
}

void insertEnd()
{
    createDll();
}

void deleteFront()
{
    if(first == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    NODE cur = first->rlink;
    free(first);
    first = cur;
    if(first != NULL)
        first->llink = NULL;
    count--;
    displayDll();
}

void deleteEnd()
{
    if(first == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    NODE cur = first, prev;
    if(first->rlink == NULL)
    {
        free(first);
        first = NULL;
        count--;
        return;
    }
    while(cur->rlink != NULL)
    {
        prev = cur;
        cur = cur->rlink;
    }
    free(cur);
    prev->rlink = NULL;
    count--;
    displayDll();
}

void displayDll()
{
    NODE cur = first;
    int c = 0;
    if(first == NULL)
    {
        printf("\nList is Empty!\n");
        return;
    }
    printf("\nSSN\tName\tDepartment\tDesignation\tSalary\tPhone\n");
    while(cur != NULL)
    {
        printf("%d\t%s\t%s\t%s\t%.2f\t%s\n", cur->ssn, cur->name, cur->dept, cur->designation, cur->sal, cur->phno);
        cur = cur->rlink;
        c++;
    }
    printf("Total Number of employees: %d\n", c);
}
