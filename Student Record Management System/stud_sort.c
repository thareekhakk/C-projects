#include "student.h"

void reverseLinks(SLL **ptr)
{
    if (*ptr == 0)
    {
        printf("No records found\n");
        return;
    }

    int c = countNode(*ptr);
    if (c > 1)
    {
        SLL **p = malloc(sizeof(SLL *) * c);
        SLL *t = *ptr;
        int i;

        for (i = 0; i < c; i++)
        {
            p[i] = t;
            t = t->next;
        }

        for (i = c - 1; i > 0; i--)
        {
            p[i]->next = p[i - 1];
        }

        p[0]->next = 0;
        *ptr = p[c - 1];
        free(p);
    }
    printf("List reversed successfully\n");
}

void sortData(SLL *ptr)
{
    if (ptr == 0)
    {
        printf("No records found\n");
        return;
    }

    char choice;
    printf("N/n: Sort with name\nP/p: Sort with percentage\nEnter choice: ");
    scanf(" %c", &choice);

    SLL *i, *j;
    int temp_roll;
    char temp_name[50];
    float temp_per;

    if (choice == 'N' || choice == 'n')
    {
        for (i = ptr; i->next != 0; i = i->next)
        {
            for (j = i->next; j != 0; j = j->next)
            {
                if (strcmp(i->name, j->name) > 0)
                {
                    temp_roll = i->rollno;
                    i->rollno = j->rollno;
                    j->rollno = temp_roll;

                    strcpy(temp_name, i->name);
                    strcpy(i->name, j->name);
                    strcpy(j->name, temp_name);

                    temp_per = i->percentage;
                    i->percentage = j->percentage;
                    j->percentage = temp_per;
                }
            }
        }
        printf("Sorted by name successfully\n");
    }
    else if (choice == 'P' || choice == 'p')
    {
        for (i = ptr; i->next != 0; i = i->next)
        {
            for (j = i->next; j != 0; j = j->next)
            {
                if (i->percentage < j->percentage)
                {
                    temp_roll = i->rollno;
                    i->rollno = j->rollno;
                    j->rollno = temp_roll;

                    strcpy(temp_name, i->name);
                    strcpy(i->name, j->name);
                    strcpy(j->name, temp_name);

                    temp_per = i->percentage;
                    i->percentage = j->percentage;
                    j->percentage = temp_per;
                }
            }
        }
        printf("Sorted by percentage successfully\n");
    }
    else
    {
        printf("Invalid choice\n");
    }
}
