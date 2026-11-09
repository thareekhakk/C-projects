#include "student.h"

void modifyNode(SLL *ptr)
{
    if (ptr == 0)
    {
        printf("No records found\n");
        return;
    }

    char choice;
    printf("Enter which record to search for modification\n");
    printf("R/r: Search by roll number\n");
    printf("N/n: Search by name\n");
    printf("P/p: Search by percentage\n");
    printf("Enter choice: ");
    scanf(" %c", &choice);

    int target_roll = -1;

    if (choice == 'R' || choice == 'r')
    {
        printf("Enter roll number: ");
        scanf("%d", &target_roll);
    }
    else if (choice == 'N' || choice == 'n')
    {
        char search_name[50];
        printf("Enter name: ");
        scanf("%s", search_name);

        int count = 0;
        SLL *temp = ptr;
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

        printf("Enter roll number to modify: ");
        scanf("%d", &target_roll);
    }
    else if (choice == 'P' || choice == 'p')
    {
        float search_percentage;
        printf("Enter percentage: ");
        scanf("%f", &search_percentage);

        int count = 0;
        SLL *temp = ptr;
        while (temp)
        {
            if (temp->percentage == search_percentage)
            {
                printf("Roll No: %d, Name: %s, Percentage: %.2f\n", temp->rollno, temp->name, temp->percentage);
                count++;
            }
            temp = temp->next;
        }

        if (count == 0)
        {
            printf("Percentage not found\n");
            return;
        }

        printf("Enter roll number to modify: ");
        scanf("%d", &target_roll);
    }
    else
    {
        printf("Invalid choice\n");
        return;
    }

    SLL *target = ptr;
    while (target)
    {
        if (target->rollno == target_roll)
            break;
        target = target->next;
    }

    if (target == 0)
    {
        printf("Record not found\n");
        return;
    }

    printf("Current details: Roll No: %d, Name: %s, Percentage: %.2f\n", target->rollno, target->name, target->percentage);
    printf("Enter updated name and percentage:\n");
    scanf("%s %f", target->name, &target->percentage);

    while (target->percentage < 0.0f || target->percentage > 100.0f)
    {
        printf("Invalid percentage! Enter between 0.00 and 100.00:\n");
        scanf("%f", &target->percentage);
    }

    printf("Record modified successfully\n");
}
