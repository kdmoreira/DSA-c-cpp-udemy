#include <stdio.h>
#include <stdlib.h>

void display(int A[], int size) // O(n)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Append/Add: adding an item to the end (next free space) of an array
void append(int A[], int *length, int item) // O(1)
{
    A[*length] = item; // Length is also the index at the next free space
    (*length)++; // Updating the length
}

// Insert: insert a new element at a given index
void insert(int index, int item, int A[], int *length) // O(n):
{
    for (int i = *length; i > index; i--)
    {
        A[i] = A[i - 1];
    }
    A[index] = item;
    (*length)++;
}

int main(void)
{
    int A[10] = {8, 3, 7, 12, 6, 9};
    int size = 10;
    int length = 6; // The values that were initialized

    display(A, size);

    // For length < size
    append(A, &length, 10);

    display(A, size);

    // For index >= 0 && index < size
    insert(3, 22, A, &length);

    display(A, size);

    return 0;
}
