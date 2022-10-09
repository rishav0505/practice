#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *createEmptyNode(int data)
{
    struct node *tail = malloc(sizeof(struct node));
    tail->data = data;
    tail->next = tail;

    return tail;
}

struct node *addAtEnd(struct node *tail, int data)
{
    struct node *temp;
    temp = createEmptyNode(data);
    temp->next = tail->next;
    tail->next = temp;
    tail = temp;

    return tail;
}
struct node *createList(struct node *tail)
{
    int data, n, i;
    struct node *temp;
    printf("Enter the no. of nodes: ");
    scanf("%d", &n);
    if(n == 0)
        return NULL;
    printf("Enter node 1: ");
    scanf("%d", &data);
    temp = createEmptyNode(data);
    for (i = 1; i < n; i++)
    {
        printf("Enter node %d: ", i + 1);
        scanf("%d", &data);
        temp = addAtEnd(temp, data);
    }
    tail = temp;

    return tail;
}
void print(struct node *tail)
{
    struct node *temp;
    temp = tail->next;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
}

void main()
{
    struct node *tail = NULL;
    tail = createList(tail);
    print(tail);
}
