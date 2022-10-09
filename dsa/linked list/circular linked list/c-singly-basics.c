#include <stdio.h>
#include <stdlib.h>

// --user defined datatype--
struct node
{
    int data;
    struct node *next;
};

// ---count no. of nodes---
void countNodes(struct node *tail)
{
    int i = 0;
    struct node *temp = tail->next;
    do
    {
        i++;
        temp = temp->next;
    } while (temp != tail->next);
    printf("\nList Length = %d", i);
}

// ---search an element in the list---
void search(struct node *tail, int data)
{
    if (tail == NULL)
        printf("\nLinked list is empty!");
    int i = 0;
    struct node *temp = tail->next;
    do
    {
        i++;
        if (temp->data == data)
        {
            printf("\n%d found in index %d!", data, i);
            return;
        }
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n%d didn't found in any of the node.", data);
}

// ---prints the linked list--- Time Complexity = O(n)
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

// --- create a empty node and store data into it---
struct node *addToEmpty(int data)
{
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;

    return temp;
}

// ---adds a node at the beggining of the list---
struct node *addAtBeg(struct node *tail, int data)
{
    struct node *temp;
    temp = addToEmpty(data);
    temp->next = tail->next;
    tail->next = temp;

    return tail;
}

// ---add a node at the end of the list---
struct node *addAtEnd(struct node *tail, int data)
{
    struct node *temp;
    temp = addToEmpty(data);

    temp->next = tail->next;
    tail->next = temp;
    tail = temp;

    return tail;
}

// ---adding a node after a giver position---
struct node *addAfterPos(struct node *tail, int data, int pos)
{
    struct node *temp1, *newP;
    newP = addToEmpty(data);
    temp1 = tail->next;

    while (--pos)
        temp1 = temp1->next;

    newP->next = temp1->next;
    temp1->next = newP;

    if (temp1 == tail)
        tail = newP;

    return tail;
}

// ---adds a node before a given position---
struct node *addBeforePos(struct node *tail, int data, int pos)
{
    struct node *newP, *temp;
    newP = addToEmpty(data);
    temp = tail->next;

    if (pos == 1)
        tail = addAtBeg(tail, data);
    else
    {
        pos -= 1;
        while (--pos)
            temp = temp->next;

        newP->next = temp->next;
        temp->next = newP;
    }
    return tail;
}

// ---delete first node of the list---
struct node *delFirstNode(struct node *tail)
{
    if (tail == NULL || tail->next == tail)
    {
        free(tail);
        tail = NULL;
        return NULL;
    }

    struct node *temp;
    temp = tail->next;
    tail->next = temp->next;
    free(temp);
    temp = NULL;

    return tail;
}

// ---delete last node of the list---
struct node *delLastNode(struct node *tail)
{
    struct node *temp1;
    temp1 = tail->next;
    while (temp1->next != tail)
        temp1 = temp1->next;

    temp1->next = tail->next;
    free(tail);
    tail = temp1;

    return tail;
}

// ---delete a node at a certain position---
struct node *delAnyPos(struct node *tail, int pos)
{
    if (tail == NULL)
        return NULL;
    if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
        return NULL;
    }
    struct node *temp1, *temp2;
    temp1 = tail->next;
    if (pos == 1)
    {
        tail->next = temp1->next;
        free(temp1);
        temp1 = NULL;
        return tail;
    }
    pos--;
    while (--pos)
        temp1 = temp1->next;
    temp2 = temp1->next;
    temp1->next = temp2->next;
    if (temp2 == tail)
        tail = temp1;
    free(temp2);
    temp2 = NULL;
    return tail;
}

void main()
{
    struct node *tail;

    // add node in circular singly linked list
    tail = addToEmpty(30);            // Time Complexity = O(1)     Data = 30
    tail = addAtBeg(tail, 20);        // Time Complexity = O(1)     Data = 20 30
    tail = addAtEnd(tail, 40);        // Time Complexity = O(1)     Data = 20 30 40
    tail = addAtBeg(tail, 10);        // Time Complexity = O(1)     Data = 10 20 30 40
    tail = addAfterPos(tail, 15, 1);  // Time Complexity = O(n)     Data = 10 15 20 30 40
    tail = addBeforePos(tail, 25, 4); // Time Complexity = O(n)     Data = 10 15 20 25 30 40

    // OutPut: 10 15 20 25 30 40
    print(tail);      // Time Complexity = O(n)
    countNodes(tail); // Time Complexity = O(n)     List Length = 3

    // deletion operations
    tail = delFirstNode(tail); // Time Complexity = O(1)    Data = 15 20 25 30 40
    tail = delLastNode(tail);  // Time Complexity = O(n)    Data = 15 20 25 30
    tail = delAnyPos(tail, 2); // Time Complexity = O(n)    Data = 15 25 30

    print(tail);      // Data = 15 25 30
    countNodes(tail); // Time Complexity = O(n)     List Length = 3

    search(tail, 30); // Time Complexity = O(n)     30 found in node 3!
}
