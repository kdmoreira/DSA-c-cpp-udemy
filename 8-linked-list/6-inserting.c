#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n)
{
    struct Node *aux, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        aux = (struct Node *)malloc(sizeof(struct Node));
        aux->data = A[i];
        aux->next = NULL;
        last->next = aux;
        last = aux;
    }
}

int count_nodes(struct Node *p) // Time: O(n), Space: O(1)
{
    int counter = 0;
    while(p != 0)
    {
        counter++;
        p = p->next;
    }
    return counter;
}

// Insert by verifying the length of the array first
void insert(struct Node *p, int index, int num)
{
    if (index < 0 || index > count_nodes(p))
    {
        return;
    }
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = num;
    if (index == 0)
    {
        new_node->next = first;
        first = new_node;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        new_node->next = p->next;
        p->next = new_node;
    }
}

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
    /* int A[] = {8, 3, 9, 7, 6};

    create(A, 5);

    display(first);
    printf("\n");

    insert(first, 0, 25); */

    /* You can insert a number in an array that was already created (commented out above)
    or create a new array by inserting, starting with index 0 and going on, see below */
    insert(first, 0, 10);
    insert(first, 1, 20);
    insert(first, 2, 30);
    insert(first, 0, 5);

    display(first);

    return 0;
}
