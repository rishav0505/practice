
#include <stdio.h>
#include <stdlib.h>

// ---create a node---
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

// ---print the linked list---
void printData(struct node *head)
{
    struct node *temp = head;
    printf("\nData = ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// ---insert a node in a empty list---
struct node *addNodeToEmptyList(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    head = temp;
    return head;
}

// ---add a node at the beggining---
struct node *addAtBeg(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

// ---add a node at the end---
void addAtEnd(struct node *head, int data)
{
    struct node *tp, *temp;
    temp = malloc(sizeof(struct node));
    tp = head;

    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    while (tp->next != NULL)
        tp = tp->next;

    tp->next = temp;
    temp->prev = tp;
}

// ---add a node after a specific position---
struct node *addAtPosAfter(struct node *head, int data, int pos)
{
    struct node *temp, *ptr1, *ptr2;
    temp = addNodeToEmptyList(temp, data);
    ptr1 = head;
    while (--pos)
        ptr1 = ptr1->next;
    if (ptr1->next == NULL)
    {
        ptr1->next = temp;
        temp->prev = ptr1;
    }
    else
    {
        ptr2 = ptr1->next;
        ptr2->prev = temp;
        ptr1->next = temp;
        temp->next = ptr2;
        temp->prev = ptr1;
    }

    return head;
}

// ---add a node before a specific position---
struct node *addAtPosBefore(struct node *head, int data, int pos)
{
    struct node *temp, *ptr1, *ptr2;
    temp = addNodeToEmptyList(temp, data);
    ptr1 = head;
    pos -= 1;
    while (--pos)
        ptr1 = ptr1->next;

    if (pos == 1)
        head = addAtBeg(head, data);
    else
    {
        ptr2 = ptr1->next;
        ptr2->prev = temp;
        ptr1->next = temp;
        temp->next = ptr2;
        temp->prev = ptr1;
    }
    return head;
}

// ---delete first node---
struct node *delFirstNode(struct node *head)
{
    struct node *temp = head;
    head = head->next;
    free(temp);
    head->prev = NULL;
    temp = NULL;

    return head;
}
// ---detete first node without using temp---
struct node *delFirstNode2(struct node *head)
{
    head = head->next;
    free(head->prev);
    head->prev = NULL;

    return head;
}
// ---delete last node---
void delLastNode(struct node *head)
{
    struct node *temp1, *temp2;
    temp1 = head;
    while (temp1->next != NULL)
        temp1 = temp1->next;
    temp2 = temp1->prev;
    temp2->next = NULL;
    free(temp1);
    temp1 = NULL;
}
// ---delete node at any position---
struct node *delAtAnyPos(struct node *head, int pos)
{
    struct node *temp1, *temp2;
    temp1 = head;

    if (pos == 1)
        head = delFirstNode2(head);
    else
    {
        while (--pos)
            temp1 = temp1->next;
        if (temp1->next == NULL)
            delLastNode(head);
        else
        {
            temp2 = temp1->prev;

            temp2->next = temp1->next;
            temp1->next->prev = temp2;
            free(temp1);
            temp1 = NULL;
        }
    }
    return head;
}

// ---reverse the list---
struct node *reverse(struct node *head)

{
    struct node *ptr1 = head;
    struct node *ptr2 = ptr1->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while (ptr2 != NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr1;
    return head;
}
void main()
{
    struct node *head = NULL;
    head = addNodeToEmptyList(head, 20); // Data = 20
    head = addAtBeg(head, 10);           // Data = 10 20

    // add nodes in diff ways
    addAtEnd(head, 30);                 // Data = 10 20 30
    addAtEnd(head, 40);                 // Data = 10 20 30 40
    head = addAtPosBefore(head, 25, 3); // Data = 10 20 25 30 40
    head = addAtPosAfter(head, 15, 1);  // Data = 10 15 20 25 30 40
    printData(head);                    // prints the linked list

    // reverse the list
    head = reverse(head);
    printData(head); // Data = 40 30 25 20 15 10

    // delete node in diff ways
    head = delFirstNode(head);   // Data = 30 25 20 15 10
    head = delFirstNode2(head);  // Data = 25 20 15 10
    delLastNode(head);           // Data = 25 20 15
    head = delAtAnyPos(head, 2); // Data = 25 15
    printData(head);             // Data = 25 15
}
