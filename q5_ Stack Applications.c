#include <stdio.h>
#include <ctype.h>   // FIX: for isdigit()

#define MAX 10

int stack[MAX], top = -1;

void push(int);
int pop();
void eval(int op1, char sym, int op2);

int main()
{
    int i = 0, op1, op2;
    char exp[20];
    char sym;

    printf("Enter postfix expression:\t");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++)
    {
        sym = exp[i];

        if (isdigit(sym))     // Check given symbol is a digit or operator
        {
            push(sym - '0');  // Symbol converted to int
        }
        else
        {
            op2 = pop();      // Pop the top ele as op2
            op1 = pop();      // Pop the next top ele as op1
            eval(op1, sym, op2);
        }
    }

    printf("Result of given expression=%d", pop());
    return 0;
}

void push(int ele)
{
    stack[++top] = ele;
}

int pop()
{
    return stack[top--];
}

void eval(int op1, char sym, int op2)
{
    int res;
    switch (sym)
    {
        case '+': res = op1 + op2;
                  push(res);
                  break;
        case '-': res = op1 - op2;
                  push(res);
                  break;
        case '*': res = op1 * op2;
                  push(res);
                  break;
        case '/': res = op1 / op2;
                  push(res);
                  break;
        case '%': res = op1 % op2;
                  push(res);
                  break;
    }
}
