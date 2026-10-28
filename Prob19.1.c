/*
Daily Question Series
Question No. 19

Write a program to detect a cycle in a Doubly Linked List.

Hint:
Use Slow and Fast Pointer Concept (Floyd's Cycle Detection Algorithm).

Time Complexity  : O(n)
Space Complexity : O(1)
*/

#include <stdio.h>
#include <stdlib.h>

/* Structure of a Doubly Linked List node */
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

/* Create a new node */
struct Node* createNode(int data)
{
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

/* Detect cycle using slow and fast pointers */
int detectCycle(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        /* Slow pointer moves one step */
        slow = slow->next;

        /* Fast pointer moves two steps */
        fast = fast->next->next;

        /* If both meet, cycle exists */
        if (slow == fast)
            return 1;
    }

    return 0;
}

int main()
{
    /*
       Creating Doubly Linked List:

       10 <-> 20 <-> 30 <-> 40

       Then creating a cycle:
       40 -> 20
    */

    struct Node *head = createNode(10);
    struct Node *second = createNode(20);
    struct Node *third = createNode(30);
    struct Node *fourth = createNode(40);

    /* Connect nodes */
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    /* Create cycle for testing */
    fourth->next = second;
    second->prev = fourth;

    /* Detect cycle */
    if (detectCycle(head))
        printf("Cycle detected in the Doubly Linked List.\n");
    else
        printf("No cycle detected in the Doubly Linked List.\n");

    return 0;
}

/*
Floyd's Cycle Detection Algorithm:

Two pointers are used:

slow -> moves 1 node at a time
fast -> moves 2 nodes at a time

If there is a cycle, slow and fast pointers will
eventually meet at the same node.

If fast reaches NULL, there is no cycle.


Complexity Analysis:

Time Complexity:
O(n)

In the worst case, the pointers traverse the linked
list until they meet or fast reaches NULL.


Space Complexity:
O(1)

Only two extra pointers (slow and fast) are used.
No additional data structure is required.
*/
