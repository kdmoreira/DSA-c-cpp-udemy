#include <stdio.h>
#include <stdlib.h>

/* Traversing a linked list: displaying all the nodes, that is, the values stored in them.
* Useful for displaying, counting, adding, sorting nodes, etc */
struct Node
{
    int data;
    struct Node *next;
}*first = NULL; // Creating a global pointer and initializing it to NULL

// Creating a linked list
void create(int A[], int n) // n is the number of elements
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Displaying a linked list:
void display(struct Node *p)
{
    // Condition to keep accessing the next values, could also be (p != NULL) or (p)
    while(p != 0)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main(void)
{
    // Creating a linked list
    int A[] = {3, 5, 7, 10, 15};

    // Creating a linked list
    create(A, 5);

    // Displaying a linked list:
    display(first);

    return 0;
}
