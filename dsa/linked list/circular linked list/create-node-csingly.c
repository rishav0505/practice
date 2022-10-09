#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *CircularSingly(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

void main()
{
    struct node *tail;
    tail = CircularSingly(10);

    printf("Data = %d", tail->data);
}
