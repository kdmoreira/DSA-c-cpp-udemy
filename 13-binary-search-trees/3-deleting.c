#include <stdio.h>
#include "tree.h"

/* Deleting: basically consists of 1. searching and 2. deleting.
Deletion occurs differently depending on: key is a leaf node, key has a single child,
key has two children, etc.
For example, if we want to delete the root node, instead of altering the rest of the
entire tree, we could substitute it by either its inorder predecessor or successor that are leaves.
Inorder predecessor: RIGHTmost child of the subtree on the LEFT.
Inorder successor: LEFTmost child of the subtree on the RIGHT.
You can choose either one randomly or base the choice on the height of the subtree, for example.
However, even using this strategy may result in making other modifications on the tree, in case
the inorder successor/predecessor has a child or not.
Time taken: depends on the height, O(log n);
subsequent modifications also depend on the height: max. O(log n) */

// Height function to choose inorder successor or predecessor
int height(struct Node *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = height(p->left);
    y = height(p->right);
    return x > y ? x + 1 : y + 1;
}

struct Node * in_predecessor(struct Node *p)
{
    while (p && p->right != NULL)
    {
        p = p->right;
    }
    return p;
}

struct Node * in_successor(struct Node *p)
{
    while (p && p->left != NULL)
    {
        p = p->left;
    }
    return p;
}

// This will search for a key and delete the key's node recursively
struct Node * rec_delete(struct Node *root, int key)
{
    struct Node *p = root;
    if (p == NULL)
        return NULL;

    // In case root is a leaf node, it can be directly deleted
    if (p->left == NULL && p->right == NULL)
    {
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }

    if (key < p->data)
        p->left = rec_delete(p->left, key);
    else if (key > p->data)
        p->right = rec_delete(p->right, key);
    else
    {
        // Choosing inorder predecessor/successor based on the height of the tree
        if (height(p->left) > height(p->right))
        {
            struct Node *q = in_predecessor(p->left);
            p->data = q->data;
            p->left = rec_delete(p->left, q->data);
        }
        else
        {
            struct Node *q = in_successor(p->right);
            p->data = q->data;
            p->right = rec_delete(p->right, q->data);
        }
    }
    return p;
}

// As seen in a previous file
struct Node * loop_insert(struct Node *root, int key)
{
    struct Node *p, *t;
    p = root;

    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->left = p->right = NULL;
        root = p;
        return root;
    }

    while (p)
    {
        t = p;
        if (key < p->data)
        {
            p = p->left;
        }
        else if (key > p->data)
        {
            p = p->right;
        }
        else
        {
            printf("Key already exists!\n");
            return root;
        }
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->left = p->right = NULL;
    if (key < t->data)
    {
        t->left = p;
    }
    else
    {
        t->right = p;
    }
    return root;
}

int main(void)
{
    struct Node *root = NULL;
    root = loop_insert(root, 10);
    loop_insert(root, 5);
    loop_insert(root, 20);
    loop_insert(root, 8);
    loop_insert(root, 30);

    inorder(root);
    printf("\n");

    rec_delete(root, 10);

    inorder(root);

    return 0;
}
