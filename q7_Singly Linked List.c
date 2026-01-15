#include<stdio.h>
#include<stdlib.h>

struct student
{
    char usn[20];
    char name[50];
    char branch[20];
    int sem;
    char phno[10];
    struct student *link;
};

typedef struct student *NODE;

int count = 0;
NODE first = NULL;

NODE createNode();
void CreateSLL();
void DisplaySLL();
void InsertFront();
void InsertEnd();
void DeleteFront();
void DeleteEnd();

int main()
{
    int ch;
    while(1)
    {
        printf("1.CreateSLL \n2.DisplaySLL \n3.Insert front \n4.Insert End \n5.Delete Front\n6.Delete End \n7.Exit\nEnter Your Choice:");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: CreateSLL(); break;
            case 2: DisplaySLL(); break;
            case 3: InsertFront(); break;
            case 4: InsertEnd(); break;
            case 5: DeleteFront(); break;
            case 6: DeleteEnd(); break;
            case 7: exit(0);
        }
    }
    return 0;
}

NODE createNode()
{
    NODE temp;
    temp = malloc(sizeof(struct student));
    printf("\n Enter Usn:");
    scanf("%s", temp->usn);
    printf("\n Enter Student Name:");
    scanf("%s", temp->name);
    printf("\n Enter branch:");
    scanf("%s", temp->branch);
    printf("\n Enter semester:");
    scanf("%d", &temp->sem);
    printf("\n Enter Phone Number:");
    scanf("%s", temp->phno);
    temp->link = NULL;
    count++;
    return temp;
}

void CreateSLL()
{
    NODE temp;
    temp = createNode();
    if(first == NULL)
        first = temp;
    else
    {
        temp->link = first;
        first = temp;
    }
    printf("Student node inserted at Front of List \n");
    DisplaySLL();
}

void DisplaySLL()
{
    NODE cur = first;
    if(first == NULL)
    {
        printf("\n Student List is empty!");
        return;
    }
    printf("\nStudents List:\n");
    printf("----------------------------------------------\n");
    while(cur != NULL)
    {
        printf("%s\t%s\t%s\t%d\t%s\n", cur->usn, cur->name, cur->branch, cur->sem, cur->phno);
        cur = cur->link;
    }
    printf("\n");
    printf("Total Number of students: %d \n", count);
}

void InsertFront()
{
    CreateSLL();
}

void InsertEnd()
{
    NODE temp, cur;
    cur = first;
    if(first == NULL)
    {
        temp = createNode();
        first = temp;
    }
    else
    {
        while(cur->link != NULL)
            cur = cur->link;
        temp = createNode();
        cur->link = temp;
    }
    printf("Student Node inserted at end of the list!\n");
    DisplaySLL();
}

void DeleteFront()
{
    if(first == NULL)
    {
        printf("Student list is empty!\n");
        return;
    }
    NODE cur;
    cur = first->link;
    free(first);
    first = cur;
    printf("Node deleted front of the list!\n");
    count--;
    DisplaySLL();
}

void DeleteEnd()
{
    if(first == NULL)
    {
        printf("Student list is empty!\n");
        return;
    }
    NODE cur = first, prev;
    if(first->link == NULL)
    {
        free(first);
        first = NULL;
        count--;
        return;
    }
    while(cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    free(cur);
    prev->link = NULL;
    printf("Node deleted end of the list!\n");
    count--;
    DisplaySLL();
}
