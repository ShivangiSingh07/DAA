/*
Question 33:
Remove the N-th Node From the End of a Linked List.

Example:
Input List:  1 -> 2 -> 3 -> 4 -> 5
N = 2
Output List: 1 -> 2 -> 3 -> 5

Approach:
Use two pointers (fast and slow).
Move fast N nodes ahead, then move both pointers together.
When fast reaches the end, slow will be just before the node
that needs to be removed.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *removeNthFromEnd(struct Node *head, int n)
{
    struct Node dummy;
    dummy.next = head;

    struct Node *fast = &dummy;
    struct Node *slow = &dummy;

    // Move fast pointer n nodes ahead
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;

        if (fast == NULL)
            return head; // n is greater than list size
    }

    // Move both pointers until fast reaches last node
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // Delete the N-th node from the end
    struct Node *temp = slow->next;
    slow->next = temp->next;
    free(temp);

    return dummy.next;
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);

        if (head->next != NULL)
            printf(" -> ");

        head = head->next;
    }

    printf("\n");
}

int main()
{
    // Creating list: 1 -> 2 -> 3 -> 4 -> 5
    struct Node *head = NULL;
    struct Node *tail = NULL;

    for (int i = 1; i <= 5; i++)
    {
        struct Node *newNode =
            (struct Node *)malloc(sizeof(struct Node));

        newNode->data = i;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int n = 2;

    printf("Original List: ");
    printList(head);

    head = removeNthFromEnd(head, n);

    printf("After removing %d-th node from end: ", n);
    printList(head);

    return 0;
}
