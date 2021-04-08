#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* Creating a binary tree with insertions:
Insert takes O(n) time, search takes O(log n): n x log n -> O(n log n) */

// Insert with loop
struct Node * loop_insert(struct Node *root, int key)
{
    struct Node *p, *t; // A pointer to create a node and another as a tail
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
        else // If key == p->data there is no need to insert the key again
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

struct Node * rec_insert(struct Node *root, int key)
{
    struct Node *p; // A pointer to create a node and a tail pointer

    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->left = p->right = NULL;
        return p;
    }
    if (key < root->data)
    {
        // This will eventually be called when the function returns to the previous call
        root->left = rec_insert(root->left, key);
    }
    else if (key > root->data)
    {
        // This will eventually be called when the function returns to the previous call
        root->right = rec_insert(root->right, key);
    }
    return root;
}

int main(void)
{
    struct Node *root = NULL;

    root = rec_insert(root, 50);
    rec_insert(root, 60);
    rec_insert(root, 30);
    rec_insert(root, 80);

    loop_insert(root, 30);
    loop_insert(root, 40);
    loop_insert(root, 50);
    loop_insert(root, 60);

    inorder(root);

    return 0;
}
