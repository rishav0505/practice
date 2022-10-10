#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};

struct node *createEmptyNode(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = temp;
    temp->data = data;
    temp->next = temp;

    return temp;
}

void print(struct node *tail)
{
    struct node *ptr = tail->next;
    printf("\nData = ");
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != tail->next);
}

struct node *insertAtEnd(struct node *tail, int data)
{
    struct node *temp1, *newP;
    newP = createEmptyNode(data);
    temp1 = tail->next;

    newP->prev = tail;
    newP->next = temp1;
    tail->next = newP;
    temp1->prev = newP;
    tail = newP;

    return tail;
}

struct node *createList(struct node *tail)
{
    int data, n, i;
    struct node *temp;
    printf("Enter the no. of nodes: ");
    scanf("%d", &n);
    if (n == 0)
        return NULL;
    printf("Enter node 1: ");
    scanf("%d", &data);
    temp = createEmptyNode(data);
    tail = temp;
    for (i = 1; i < n; i++)
    {
        printf("Enter node %d: ", i + 1);
        scanf("%d", &data);
        temp = insertAtEnd(temp, data);
    }
    tail = temp;
    
    return tail;
}

void main()
{
    struct node *tail = NULL;
    tail = createList(tail);
    print(tail);

}
