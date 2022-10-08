
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void main()
{
    struct node *head = NULL;
    head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;
    printf("data  = %d", head->data);
}
