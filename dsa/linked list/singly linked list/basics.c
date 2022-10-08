
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

// ---count no. of nodes---
void countNodes(struct node *head)
{
    if (head == NULL)
        printf("Linked list is empty!");
    int i = 0;
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        i++;
        ptr = ptr->link;
    }
    printf("Length of linked list : %d\n", i);
}

// ---print linked list---
void printData(struct node *head)
{
    if (head == NULL)
        printf("Linked list is empty!");
    else
    {
        struct node *ptr = NULL;
        ptr = head;
        printf("Data = ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }
    }
}

// ---add node at the end---
void addAtEnd(struct node *head, int data)
{
    struct node *ptr, *temp;
    ptr = head;
    temp = malloc(sizeof(struct node));

    temp->data = data;
    temp->link = NULL;

    while (ptr->link != NULL)
        ptr = ptr->link;
    ptr->link = temp;
}

// ---add node at begining (returning the node)---
struct node *addAtBeg(struct node *head, int data)
{
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    temp->link = head;
    head = temp;

    return head;
}

// ---add node at begining (without returning node)---
void addAtBeg2(struct node **head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    temp->link = *head;
    *head = temp;
}

// --add node at any position---
void addAtPosition(struct node *head, int data, int position)
{
    struct node *ptr = head, *temp = malloc(sizeof(struct node));
    temp->data = data;
    while (position > 2)
    {
        ptr = ptr->link;
        position--;
    }
    temp->link = ptr->link;
    ptr->link = temp;
}

// ---delete first node---
struct node *del_first(struct node *head)
{
    if (head == NULL)
        printf("Linked list is empty!");
    else
    {
        struct node *temp = head;
        head = head->link;
        free(temp);
        temp = NULL;
    }
    return head;
}

// ---delete last node using 2 pointers---
void del_last(struct node *head)
{
    if (head == NULL)
        printf("Linked list is empty!");

    // if linked list is 1
    else if (head->link == NULL)
    {
        free(head);
        head = NULL;
    }

    // if linked list is more than 1
    else
    {
        struct node *temp1, *temp2;
        temp1 = head;
        temp2 = head;
        while (temp1->link != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->link;
        }
        temp2->link = NULL;
        free(temp1);
        temp1 = NULL;
    }
}

// ---delete last node using single pointer---
void del_last2(struct node *head)
{
    if (head == NULL)
        printf("Linked list is empty!");

    // if linked list is 1
    else if (head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    // if linked list is more than 1
    else
    {
        struct node *temp = head;
        while (temp->link->link != NULL)
            temp = temp->link;

        free(temp->link);
        temp->link = NULL;
    }
}

// ---delete node at any position---
struct node *delAtPosition(struct node *head, int pos)
{
    if (head == NULL)
        printf("Linked list is empty!");
    else if (pos == 1)
    {
        struct node *temp = head;
        head = head->link;
        free(temp);
        temp = NULL;
    }
    else
    {
        struct node *prev, *current;
        current = head;
        while (--pos)
        {
            prev = current;
            current = current->link;
        }
        prev->link = current->link;
        free(current);
        current = NULL;
    }
    return head;
}

// ---delete linked list---
struct node *del_list(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        temp = temp->link;
        free(head);
        head = temp;
    }
    return head;
}

// ---reverse linked list---
struct node *rev_list(struct node *head)
{
    struct node *prev, *next;
    next = NULL;
    prev = NULL;
    while (head != NULL)
    {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}

void main()
{
    struct node *head = NULL;

    head = (struct node *)malloc(sizeof(struct node));
    head->data = 40;
    head->link = NULL;

    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->data = 50;

    head->link = current;
    head->link->link = NULL;

    struct node *current2 = (struct node *)malloc(sizeof(struct node));
    current2->data = 60;
    head->link->link = current2;
    head->link->link->link = NULL;

    // printf("Data = %d %d %d\n", head->data, head->link->data, head->link->link->data);

    // addition operations
    addAtEnd(head, 70);
    addAtBeg2(&head, 30);
    head = addAtBeg(head, 20);
    addAtPosition(head, 25, 2);
    addAtPosition(head, 35, 4);

    // count & print
    printf("Linked list before deletion:\n");
    countNodes(head); // Length of linked list : 8
    printData(head);  // Data = 20 25 30 35 40 50 60 70

    // deletion operations
    head = del_first(head);        // Data = 25 30 35 40 50 60 70
    del_last(head);                // Data = 25 30 35 40 50 60
    del_last2(head);               // 25 30 35 40 50
    head = delAtPosition(head, 2); // Data = 25 35 40 50

    // delete linked list
    /*
    head = del_list(head);
    if(head==NULL)
        printf("\nLinked list deleted succesfully!");
    */

    // count & print
    printf("\nLinked list after deletion:\n");
    countNodes(head);
    printData(head);

    // reverse linked list
    head = rev_list(head);
    printf("\nReversed linked list: \n");
    printData(head);
}
