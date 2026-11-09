#include "student.h"

void deleteNode(SLL **ptr)
{
    if (*ptr == 0)
    {
        printf("No records found\n");
        return;
    }

    char choice;
    printf("R/r: Enter roll number to delete\nN/n: Enter name to delete\nEnter choice: ");
    scanf(" %c", &choice);

    int roll_to_del = -1;

    if (choice == 'R' || choice == 'r')
    {
        printf("Enter roll number: ");
        scanf("%d", &roll_to_del);
    }
    else if (choice == 'N' || choice == 'n')
    {
        char search_name[50];
        printf("Enter name: ");
        scanf("%s", search_name);

        int count = 0;
        SLL *temp = *ptr;
        while (temp)
        {
            if (strcmp(temp->name, search_name) == 0)
            {
                printf("Roll No: %d, Name: %s, Percentage: %.2f\n", temp->rollno, temp->name, temp->percentage);
                count++;
            }
            temp = temp->next;
        }

        if (count == 0)
        {
            printf("Name not found\n");
            return;
        }

        printf("Enter roll number to delete: ");
        scanf("%d", &roll_to_del);
    }
    else
    {
        printf("Invalid choice\n");
        return;
    }

    SLL *del = *ptr;
    SLL *prev = 0;

    while (del)
    {
        if (del->rollno == roll_to_del)
            break;
        prev = del;
        del = del->next;
    }

    if (del == 0)
    {
        printf("Record not found\n");
        return;
    }

    if (prev == 0)
        *ptr = del->next;
    else
        prev->next = del->next;

    free(del);
    printf("Record deleted successfully\n");
}

void deleteAll(SLL **ptr)
{
    if (*ptr == 0)
    {
        printf("No records found\n");
        return;
    }

    SLL *del = *ptr;
    int c = 1;

    while (del)
    {
        *ptr = del->next;
        printf("Node %d deleted\n", c++);
        free(del);
        del = *ptr;
    }
}
