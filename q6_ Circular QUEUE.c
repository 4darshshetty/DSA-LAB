#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 5

char cqueue[MAX], element;
int front = 0, rear = -1, count = 0;

void insert(char ele);
void delete();
void display();

int main()
{
    int ch;
    while (1)
    {
        printf("\n1.insert\n2.delete\n3.display\n4.exit\nEnter Your Choice:");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("\n Enter a char element to insert:");
                scanf(" %c", &element);
                insert(element);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;
        }
    }
    return 0;
}

void insert(char ele)
{
    if (count == MAX)
    {
        printf("Circular Queue is full\n");
        return;
    }

    rear = (rear + 1) % MAX;
    cqueue[rear] = ele;
    count++;
    printf("Element inserted into C-Queue.\n");
}

void delete()
{
    if (count == 0)
    {
        printf("Circular Queue is empty\n");
        return;
    }

    printf("Element deleted from C-Queue: %c\n", cqueue[front]);
    front = (front + 1) % MAX;
    count--;
}

void display()
{
    int i;
    if (count == 0)
    {
        printf("\n Circular Queue is empty!\n");
        return;
    }
    else
    {
        for (i = front; i != rear; i = (i + 1) % MAX)
        {
            printf("%c\n", cqueue[i]);
        }
        printf("%c\n", cqueue[i]);
    }
}
