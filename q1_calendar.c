#include <stdio.h>
#include <stdlib.h>   // FIX 1: for malloc() and exit()

void create(void);
void read(void);
void display(void);

int n = 7;       // Number of array elements

struct calendar
{
    char *day;
    int date;
    char *activity;
};

struct calendar *cal;

int main()
{
    int ch;
    while (1)
    {
        printf("1.Create\n2.Read \n3.Display() \n4.Exit\nEnter your choice:");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1: create();
                    break;

            case 2: read();
                    break;

            case 3: display();
                    break;

            case 4: exit(0);
        }
    }
    return 0;
}

void create(void)    // Allocate memory for the calendar
{
    printf("\n Allocating the memory\n");
    cal = malloc(n * sizeof(struct calendar));
    printf("\n Memory Allocated! \n");
}

void read(void)   // Read 7 days week activities
{
    int i;
    char temp;

    for (i = 0; i < n; i++)
    {
        printf("\n Enter day name: ");
        cal[i].day = (char *)malloc(10);
        scanf("%s", cal[i].day);

        printf("\n Enter date: ");
        scanf("%d", &cal[i].date);

        printf("\n Enter Activity name: ");
        cal[i].activity = (char *)malloc(50);
        scanf("%c", &temp);   // clear buffer

        fgets(cal[i].activity, 50, stdin);   // FIX 2: replaced gets()
    }
}

void display(void)
{
    int i;
    printf("\n Activities List \n");
    printf("\nSL No  Day_Name\t\tDate\tActivity_Name \n");

    for (i = 0; i < n; i++)
    {
        printf("%d. %s\t%d\t%s\n",
               i + 1, cal[i].day, cal[i].date, cal[i].activity);
    }
    printf("\n");
}
