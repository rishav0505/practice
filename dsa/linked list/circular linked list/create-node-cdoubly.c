// line no. 7 & 15 are added, rest are same as singly circular.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *CircularDoubly(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = temp;
    temp->data = data;
    temp->next = temp;
    return temp;
}

void main() 
{
    struct node *tail;
    tail = CircularDoubly(10);

    printf("Data = %d", tail->data);
}
