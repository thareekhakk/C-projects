#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
} SLL;

void addNode(SLL **ptr);
void deleteNode(SLL **ptr);
void printNode(SLL *ptr);
void modifyNode(SLL *ptr);
void saveFile(SLL *ptr);
void readFile(SLL **ptr);
void deleteAll(SLL **ptr);
void reverseLinks(SLL **ptr);
void sortData(SLL *ptr);
int countNode(SLL *ptr);
