#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr)
{
    for (int i = 0; i < arr.size; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

// Append/Add: adding an item to the end (next free space) of an array
void append(struct Array *arr, int item) // Call by address since it will modify the array
{
    if (arr->length < arr->size)
    {
        // Possible to store and increment length at the same time
        arr->A[arr->length++] = item;
    }
}

// Insert: insert a new element at a given index
void insert(int index, int item, struct Array *arr)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = item;
        arr->length++;
    }
}

int main(void)
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    display(arr);

    // For length < size
    append(&arr, 10);

    display(arr);

    // For index >= 0 && index < size
    insert(3, 22, &arr);

    display(arr);


    return 0;
}

