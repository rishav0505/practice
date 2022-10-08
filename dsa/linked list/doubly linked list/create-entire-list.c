
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *createEmptyNode(struct node *head, int data)
{
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void addAtEnd(struct node *head, int data)
{
    struct node *temp, *ptr;
    ptr = head;
    temp = createEmptyNode(temp, data);

    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = temp;
    temp->prev = ptr;
}

struct node *createList(struct node *head)
{
    int n, i, data;
    printf("Enter the no. of nodes: ");
    scanf("%d", &n);
    if (n == 0)
        return head;
    printf("Enter node 1: ");
    scanf("%d", &data);
    head = createEmptyNode(head, data);
    for (i = 1; i < n; i++)
    {
        printf("Enter node %d: ", i + 1);
        scanf("%d", &data);
        addAtEnd(head, data);
    }
    return head;
}

void printList(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

void main()
{
    struct node *head;
    head = createList(head);
    printList(head);
}
