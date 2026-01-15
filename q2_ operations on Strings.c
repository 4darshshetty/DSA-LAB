#include <stdio.h>
#include <stdlib.h>   // FIX 1: for exit()

char str[100], pat[100], rep[100], res[100];
int i, j, c, m, k, flag = 0;

void read(void);
void replace(void);

int main()
{
    int ch;
    while (1)
    {
        printf("\n 1.Read Strings \n 2.Replace \n 3.Exit\n Enter Your Choice:");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1: read();
                    break;

            case 2: replace();
                    break;

            case 3: exit(0);
        }
    }
    return 0;
}

void read(void)   // FIX 2: prototype match
{
    char temp;
    scanf("%c", &temp);   // clear buffer

    printf("\n Enter main string:\n");
    fgets(str, 100, stdin);     // FIX 3: replaced gets()

    printf("\n Enter pattern string:\n");
    fgets(pat, 100, stdin);     // FIX 3

    printf("\n Enter replacement string:\n");
    fgets(rep, 100, stdin);     // FIX 3
}

void replace(void)
{
    i = m = c = j = 0;
    flag = 0;

    while (str[c] != '\0')
    {
        if (str[m] == pat[i])
        {
            i++;
            m++;
            if (pat[i] == '\0')
            {
                for (k = 0; rep[k] != '\0'; k++, j++)
                    res[j] = rep[k];

                i = 0;
                c = m;
                flag = 1;
            }
        }
        else
        {
            res[j] = str[c];
            j++;
            c++;
            m = c;
            i = 0;
        }
    }

    if (flag == 0)
        printf("pattern doesn't found!!!\n");
    else
    {
        res[j] = '\0';
        printf("\n The RESULTANT string is: %s\n", res);
    }
}
