#include <stdio.h>
#include <stdlib.h>

/* You can create a linked list by using the insert function seen previously.
Additionally, if the insertion always happens at the end of the LL, it's recommended
using a "last" pointer so that the insertion occurs at constant time O(1) */

struct Node
{
    int data;
    struct Node *next;
}*first = NULL, *last = NULL;

int count_nodes(struct Node *p)
{
    int counter = 0;
    while(p != 0)
    {
        counter++;
        p = p->next;
    }
    return counter;
}

void display(struct Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// An insert function without "last", that can insert a node in any position given the index
void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    if (index < 0 || index > count_nodes(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

// This function only inserts at the end of the LL
void insert_last(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (first == NULL) // In case there aren't any nodes
    {
        first = last = t; // Both pointing at the same node that has been created
    }
    else
    {
        last->next = t;
        last = t;
    }
}

int main(void)
{
    // Using both kinds of insertions

    insert_last(2);
    insert_last(4);
    insert_last(6);

    insert(first, 1, 3);

    display(first);

    insert(first, 0, 1);
    insert(first, 4, 5);

    insert_last(7);

    display(first);

    return 0;
}

