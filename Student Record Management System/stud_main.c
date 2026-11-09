#include "student.h"

int main()
{
    SLL *headptr = 0;
    char op;

    readFile(&headptr);

    while (1)
    {
        printf("\n*** STUDENT RECORD MENU ***\n");
        printf("a/A: Add new record\n");
        printf("d/D: Delete a record\n");
        printf("s/S: Show the list\n");
        printf("m/M: Modify a record\n");
        printf("v/V: Save records\n");
        printf("t/T: Sort the list\n");
        printf("l/L: Delete all the records\n");
        printf("r/R: Reverse the list\n");
        printf("e/E: Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &op);

        switch (op)
        {
            case 'a':
            case 'A':
                addNode(&headptr);
                break;

            case 'd':
            case 'D':
                deleteNode(&headptr);
                break;

            case 's':
            case 'S':
                printNode(headptr);
                break;

            case 'm':
            case 'M':
                modifyNode(headptr);
                break;

            case 'v':
            case 'V':
                saveFile(headptr);
                break;

            case 't':
            case 'T':
                sortData(headptr);
                break;

            case 'l':
            case 'L':
                deleteAll(&headptr);
                break;

            case 'r':
            case 'R':
                reverseLinks(&headptr);
                break;

            case 'e':
            case 'E':
            {
                char exit_ch;
                printf("S/s: Save and exit\nE/e: Exit without saving\nEnter choice: ");
                scanf(" %c", &exit_ch);

                if (exit_ch == 'S' || exit_ch == 's')
                    saveFile(headptr);

                deleteAll(&headptr);
                exit(0);
            }

            default:
                printf("Unknown choice\n");
        }
    }

    return 0;
}
