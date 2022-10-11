#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *createEmptyNode(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    return temp;
}
void printData(struct node *head)
{
    if (head == NULL)
        printf("Linked list is empty!");
    else
    {
        struct node *ptr = NULL;
        ptr = head;
        printf("\nData = ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }
    }
}
void addAtEnd(struct node *head, int data)
{
    struct node *ptr, *temp;
    ptr = head;
    temp = createEmptyNode(data);
    while (ptr->link != NULL)
        ptr = ptr->link;
    ptr->link = temp;
}
void swap(struct node **a, struct node **b)
{
    int data;
    data = (*a)->data;
    (*a)->data = (*b)->data;
    (*b)->data = data;
}
struct node *sort(struct node *head)
{
    if (head == NULL)
        return NULL;
    struct node *i, *j, *temp;

    for (i = head; i != NULL; i = i->link)
        for (j = i->link; j != NULL; j = j->link)
            if (i->data > j->data)
                swap(&i, &j);

    return head;
}
struct node *addElement(struct node *head, int data)
{
    struct node *temp = head, *newP = createEmptyNode(data);
    if (head == NULL || head->data >= data)
    {
        newP->link = head;
        return newP;
    }
    while (temp->link != NULL && temp->link->data < data)
        temp = temp->link;

    newP->link = temp->link;
    temp->link = newP;

    return head;
}
void main()
{
    struct node *head = NULL;
    int arr[10] = {56, 78, 98, 23, 44, 89, 66, 35, 45, 39}, i = 1, n;
    head = createEmptyNode(54);
    for (; i < 10; i++)
        addAtEnd(head, arr[i]);

    sort(head);
    printData(head);

    printf("\nEnter the element to insert in a sorted list: ");
    scanf("%d", &n);
    head = addElement(head, n);
    printData(head);
}
