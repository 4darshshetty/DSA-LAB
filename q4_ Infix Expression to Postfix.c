#include <stdio.h>
#include <ctype.h>

char stack[20];
int top = -1;

void push(char ele);
char pop();
int priority(char sym);

int main()
{
    int i = 0;
    char exp[20];
    char sym, ele;

    printf("Enter valid Infix expression:");
    scanf("%s", exp);

    printf("\n Postfix:");

    for (i = 0; exp[i] != '\0'; i++)
    {
        sym = exp[i];

        if (isalnum(sym))
            printf("%c ", sym);

        else if (sym == '(')
            push(sym);

        else if (sym == ')')
        {
            while ((ele = pop()) != '(')
                printf("%c ", ele);
        }
        else
        {
            // FIX: check top != -1 before accessing stack[top]
            while (top != -1 && priority(stack[top]) >= priority(sym))
                printf("%c ", pop());

            push(sym);
        }
    }

    while (top != -1)
    {
        printf("%c ", pop());
    }

    return 0;
}

void push(char ele)
{
    stack[++top] = ele;
}

char pop()
{
    return stack[top--];
}

int priority(char sym)
{
    if (sym == '(')
        return 0;
    if (sym == '+' || sym == '-')
        return 1;
    if (sym == '*' || sym == '/' || sym == '%')
        return 2;
    if (sym == '^')
        return 3;
    return 0;
}
