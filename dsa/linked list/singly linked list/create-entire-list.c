#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *createEmptyNode(struct node *head, int data)
{
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    return temp;
}

void addAtEnd(struct node *head, int data)
{
    struct node *ptr, *temp;
    ptr = head;
    temp = createEmptyNode(temp, data);

    while (ptr->link != NULL)
        ptr = ptr->link;
    ptr->link = temp;
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
    if (head == NULL)
        printf("Linked list is empty!");
    else
    {
        struct node *ptr = NULL;
        ptr = head;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }
    }
}

void main()
{
    struct node *head;
    head = createList(head);
    printList(head);
}
