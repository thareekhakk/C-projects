#include "student.h"

void saveFile(SLL *ptr)
{
    if (ptr == 0)
    {
        printf("No records found\n");
        return;
    }

    FILE *fp = fopen("student.dat", "w");
    if (fp == 0)
    {
        printf("Error opening file for saving\n");
        return;
    }

    while (ptr)
    {
        fprintf(fp, "%d %s %f\n", ptr->rollno, ptr->name, ptr->percentage);
        ptr = ptr->next;
    }

    printf("DATA saved\n");
    fclose(fp);
}

void readFile(SLL **ptr)
{
    FILE *fp = fopen("student.dat", "r");
    if (fp == 0)
    {
        printf("student.dat not present\n");
        return;
    }

    while (1)
    {
        SLL *new = malloc(sizeof(SLL));
        if (fscanf(fp, "%d %s %f", &new->rollno, new->name, &new->percentage) != 3)
        {
            free(new);
            break;
        }

        new->next = 0;

        if (*ptr == 0)
        {
            *ptr = new;
        }
        else
        {
            SLL *last = *ptr;
            while (last->next)
                last = last->next;
            last->next = new;
        }
    }

    fclose(fp);
}
