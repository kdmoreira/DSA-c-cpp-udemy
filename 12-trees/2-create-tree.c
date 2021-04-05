#include <stdio.h>

/* The tree will be composed of Nodes and their data addresses inserted into a Queue,
therefore, this is a queue using linked list, with front and rear following the logic
of a circular queue */

// Node & Queue structures (could go into a header file)

struct Node
{
    int data;
    struct Node *left; // Left child
    struct Node *right; // Right child
}*root = NULL;

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q; // Since it will hold struct Node addresses
};

void create_queue(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *node)
{
    if ((q->rear + 1) % q->size == q->front) // Just like the logic of a circular queue
        printf("Queue is full!\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = node;
    }
}

struct Node * dequeue(struct Queue *q)
{
    struct Node *x = NULL;
    if (q->front == q->rear)
        printf("Queue is empty!\n");
    else
    {
        /* In this implementation, the dequeue function doesn't
        free the dequeued node's memory, since it's not out intention
        to delete it from the queue, instead, we only want to point at
        int in our create_tree function */

        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}

// Creating a Tree

void create_tree()
{
    struct Node *p, *t;
    int data;
    struct Queue q;
    create_queue(&q, 100);

    printf("Enter root value: ");
    scanf("%d", &data);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = data;
    root->left = root->right = NULL;

    enqueue(&q, root);

    while(!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter %d 's left child: ", p->data);
        scanf("%d", &data);
        if (data != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = data;
            t->left = t->right = NULL;
            p->left = t;
            enqueue(&q, t);
        }
        printf("Enter %d's right child: ", p->data);
        scanf("%d", &data);
        if (data != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = data;
            t->left = t->right = NULL;
            p->right = t;
            enqueue(&q, t);
        }
    }
}

void preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(struct Node *p)
{
    if (p)
    {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}

void postorder(struct Node *p)
{
    if (p)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->data);
    }
}

int main (void)
{
    create_tree();

    printf("\nPreOrder: ");
    preorder(root);
    printf("\nPostOrder: ");
    postorder(root);
    printf("\nInOrder: ");
    inorder(root);

    return 0;
}
