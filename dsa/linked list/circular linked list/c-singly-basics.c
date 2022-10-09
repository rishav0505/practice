#include <stdio.h>
#include <stdlib.h>

// --user defined datatype--
struct node
{
    int data;
    struct node *next;
};

// ---prints the linked list--- Time Complexity = O(n)
void print(struct node *tail)
{
    struct node *ptr = tail->next;
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

void main()
{
    struct node *tail;

    // add node in circular singly linked list
    tail = addToEmpty(30);            // Time Complexity = O(1)
    tail = addAtBeg(tail, 20);        // Time Complexity = O(1)
    tail = addAtEnd(tail, 40);        // Time Complexity = O(1)
    tail = addAtBeg(tail, 10);        // Time Complexity = O(1)
    tail = addAfterPos(tail, 15, 1);  // Time Complexity = O(n)
    tail = addBeforePos(tail, 25, 4); // Time Complexity = O(n)

    // OutPut: 10 15 20 25 30 40
    print(tail); // Time Complexity = O(n)
}
