#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* Binary Search Tree:
Requirements: 1. No duplicates, 2. Inorder gives sorted order, 3. Number of BST for 'n' nodes:
T(n) = (2n Cn)/n+1, note that for each shape numbers can be filled in only one way to get the
same in-order.
Search: a pointer will look for a key while comparing if it's greater or lower than the current
node's key.
Time taken: O(H), since it depends on the height of the tree, remember: log n <= H <= n
Successful search: O(log n) || Unsuccessful search: O(n) */

// Recursive function (a tail recursion)
struct Node * rec_search(struct Node *root, int key)
{
    struct Node *p;
    p = root;

    if (p == NULL)
    {
        printf("Not found!\n");
        return NULL;
    }
    else if (p->data == key)
    {
        printf("Found!\n");
        return p;
    }
    else if (key < p->data)
    {
        rec_search(p->left, key);
    }
    else
    {
        rec_search(p->right, key);
    }
}

// Iterative function
struct Node * loop_search(struct Node *root, int key)
{
    struct Node *p;
    p = root;

    while (p)
    {
        if (p->data == key)
        {
            printf("Found!\n");
            return p;
        }
        else if (key < p->data)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    printf("Not found!\n");
    return NULL;
}

int main(void)
{
    struct Node *root = NULL;

    root = create_tree(&root);

    rec_search(root, 40);
    loop_search(root, 30);

    return 0;
}
