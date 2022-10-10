#include <stdio.h>
#include <stdlib.h>

// user defined datatype
struct node
{
    int data;
    struct node *prev, *next;
};

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

// create a empty node
struct node *createEmptyNode(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = temp;
    temp->data = data;
    temp->next = temp;

    return temp;
}

// to insert a node at the beggining of the list
struct node *insertAtBeg(struct node *tail, int data)
{
    struct node *newP, *temp;
    newP = createEmptyNode(data);
    temp = tail->next;

    newP->prev = tail;
    newP->next = temp;
    temp->prev = newP;
    tail->next = newP;

    return tail;
}

// insert a node at the end of the list
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

// insert a node before a specific position
struct node *insertBeforePos(struct node *tail, int data, int pos)
{
    if (tail == NULL)
        return tail;

    struct node *temp1, *newP;
    newP = createEmptyNode(data);
    temp1 = tail->next;
    if (pos == 1)
    {
        newP->next = temp1;
        newP->prev = tail;
        temp1->prev = newP;
        tail->next = newP;

        return tail;
    }
    pos--;
    while (--pos)
        temp1 = temp1->next;

    newP->next = temp1->next;
    newP->prev = temp1;
    temp1->next->prev = newP;
    temp1->next = newP;

    return tail;
}

// insert a node after a specific position
struct node *insertAfterPos(struct node *tail, int data, int pos)
{
    struct node *temp1, *newP;
    newP = createEmptyNode(data);
    temp1 = tail->next;

    if (tail == NULL)
        return newP;

    while (--pos)
        temp1 = temp1->next;

    newP->next = temp1->next;
    newP->prev = temp1;
    temp1->next->prev = newP;
    temp1->next = newP;

    if (temp1 == tail)
        tail = newP;

    return tail;
}

// delete first node
struct node *delFirstNode(struct node *tail)
{
    if (tail == NULL)
        return tail;
    struct node *temp = tail->next;

    if (temp == tail)
    {
        free(tail);
        tail = NULL;
        return NULL;
    }

    tail->next = temp->next;
    temp->next->prev = tail;

    free(temp);
    temp = NULL;

    return tail;
}

// delete last node
struct node *delLastNode(struct node *tail)
{
    struct node *temp;
    temp = tail->next;

    if (temp == tail)
    {
        free(temp);
        temp = tail = NULL;
        return tail;
    }
    temp = tail->prev;
    temp->next = tail->next;
    tail->next->prev = temp;

    free(tail);
    tail = temp;

    return tail;
}

// delete a node at a certain position
struct node *delAtPos(struct node *tail, int pos)
{
    struct node *temp = tail->next;
    while (--pos)
        temp = temp->next;

    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;

    if (temp == tail)      // line 1
        tail = tail->prev; // line 2

    free(temp);
    return tail;
}

void main()
{
    struct node *tail;
    tail = createEmptyNode(30);          // Time Complexity = O(1)      Data = 30
    tail = insertAtBeg(tail, 20);        // Time Complexity = O(1)      Data = 20 30
    tail = insertAtBeg(tail, 10);        // Time Complexity = O(1)      Data = 10 20 30
    tail = insertAtEnd(tail, 40);        // Time Complexity = O(1)      Data = 10 20 30 40
    tail = insertAtEnd(tail, 50);        // Time Complexity = O(1)      Data = 10 20 30 40 50
    tail = insertBeforePos(tail, 15, 2); // Time Complexity = O(n)      Data = 10 15 20 30 40 50
    tail = insertAfterPos(tail, 25, 3);  // Time Complexity = O(n)      Data = 10 15 20 25 30 40 50
    print(tail);                         // Time Complexity = O(n)      Data = 10 15 20 25 30 40 50

    // deletion operations
    tail = delFirstNode(tail); // Time Complexity = O(1)
    tail = delLastNode(tail);  // Time Complexity = O(1)
    tail = delAtPos(tail, 2);  // Time Complexity = O(n)                Data = 10 15 20 25 30 40
    print(tail);
}
