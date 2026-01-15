#include <stdio.h>
#include <stdlib.h>   // FIX 1: for exit()

#define MAX 6

int stack[MAX], ele, num, top = -1;

void push(int);
int pop();
void checkpalindrome(int);
void stakstatus();
void display();

int main()
{
    int ch;
    while (1)
    {
        printf("\n1.Push \n2.Pop \n3.Check Palindrome \n4.Stack Status\n5.Display\n6.Exit \nEnter Your choice: ");
        // FIX 2: corrected broken string

        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("\n Enter element to Push: ");
                scanf("%d", &ele);
                push(ele);
                break;

            case 2:
                ele = pop();
                printf("\n Popped element from stack: %d", ele);
                break;

            case 3:
                printf("\nEnter a number to check Palindrome or Not:");
                scanf("%d", &num);
                checkpalindrome(num);
                break;

            case 4:
                stakstatus();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);
        }
    }
}

void push(int ele)
{
    if (top == MAX - 1)
    {
        printf("\n Stack is Overflow...\n");
    }
    else
    {
        stack[++top] = ele;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("\n Stack is underflow! \n");
        return -1;          // FIX 3: return value added
    }
    else
    {
        return stack[top--];
    }
}

void checkpalindrome(int num)
{
    int temp, rem = 0, poppedele;
    int flag = 0;

    top = -1;     // make stack empty
    temp = num;

    while (temp != 0)
    {
        rem = temp % 10;
        push(rem);
        temp = temp / 10;
    }

    while (num != 0)
    {
        rem = num % 10;
        poppedele = pop();

        if (rem != poppedele)
        {
            flag = 1;
        }
        num = num / 10;
    }

    if (flag == 0)
        printf("Given Number is palindrome\n");
    else
        printf("Given Number is not a palindrome!\n");
}

void stakstatus()
{
    if (top == MAX - 1)
    {
        printf("Stack is Full!");
    }
    display();
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack eles are \n");
        for (i = top; i >= 0; i--)
        {
            printf("%d \n", stack[i]);
        }
    }
}
