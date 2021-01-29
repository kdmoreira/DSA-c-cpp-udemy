#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main(void)
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node)); // C
    // For C++: p = new Node;

    p->data = 99;
    p->next = 0; // Or p->next = NULL; (both will store a NULL address)
    printf("Data: %d\n", p->data); // Output: 99

    // Note:
    struct Node *q;
    q = p; // q will point to the address stored in p, that is, p->data
    q = p->next; /* Now q will point to the address of next, in this case is NULL,
    but there could be an address in there, so q would be pointing to another node's data */
    p = p->next; /* Now p is pointing to NULL in this case, or what could be the address of
    another node's data */

    return 0;
}
