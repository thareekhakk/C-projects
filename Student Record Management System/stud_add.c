#include "student.h"

void addNode(SLL **ptr)
{
    SLL *new = malloc(sizeof(SLL));
    SLL *temp;
    int roll = 1;

    while (1)
    {
        temp = *ptr;
        while (temp)
        {
            if (temp->rollno == roll)
                break;
            temp = temp->next;
        }
        if (temp == 0)
            break;
        roll++;
    }

    new->rollno = roll;

    printf("Enter name and percentage:\n");
    scanf("%s %f", new->name, &new->percentage);

    while (new->percentage < 0.0f || new->percentage > 100.0f)
    {
        printf("Invalid percentage! Enter between 0.00 and 100.00:\n");
        scanf("%f", &new->percentage);
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
