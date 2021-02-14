#include <stdio.h>
#include <stdlib.h>

// To implement a stack using an array you need: an array, its size, a top pointer (int type)

struct Stack
{
    int size;
    int top;
    int *s; // The size of the array is decided at runtime
};

// Create: stack's size is given by user input
void create(struct Stack *st)
{
    printf("Enter size: ");
    scanf("%d", &st->size);
    st->s = (int *)malloc(st->size * sizeof(int));
    st->top = -1;
}

// Display: from the topmost to the lowest position
void display(struct Stack st)
{
    for (int i = st.top; i >= 0; i--)
    {
        printf("%d ", st.s[i]);
    }
}

// Push: insert an element at the topmost position
void push(struct Stack *st, int num) // O(1)
{
    if (st->top == st->size - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        st->top++;
        st->s[st->top] = num;
    }
}

// Pop: removes the topmost element from the stack and returns it
int pop(struct Stack *st) // O(1)
{
    int popped = -1;
    if (st->top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        popped = st->s[st->top];
        st->top--;
    }
    return popped;
}

/* Peek: finds element at a given position (pos starts from top, contrary to index)
position = top - pos + 1 */
int peek(struct Stack st, int pos) // O(1)
{
    int value = -1;
    if ((st.top - pos + 1) < 0)
    {
        printf("Invalid position");
    }
    else
    {
        value = st.s[st.top - pos + 1];
    }
    return value;
}

// Stack top: Shows the topmost element
int stack_top(struct Stack st)
{
    if (st.top == -1)
        return -1;
    else
        return st.s[st.top];
}

// Is Empty
int is_empty(struct Stack st)
{
    if (st.top == -1)
        return 1;
    else
        return 0;
}

// Is Full
int is_full(struct Stack st)
{
    if (st.top == st.size - 1)
        return 1;
    else
        return 0;
}

int main(void)
{
    /* Conditions:
    if (top == -1): stack is empty
    if (top == size - 1): stack is full */

    // Operations on the stack:
    struct Stack st;
    create(&st); // Suppose the size is 5

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);
    push(&st, 60); // This one will cause a stack overflow

    display(st);
    printf("\n");

    printf("%d \n", pop(&st)); // 50

    display(st);
    printf("\n");

    peek(st, 3);
    printf("Peek: %d \n", peek(st, 3));

    printf("Stack top: %d \n", stack_top(st));

    printf("Is empty: %d \n", is_empty(st));

    printf("Is full: %d \n", is_full(st));

    return 0;
}
