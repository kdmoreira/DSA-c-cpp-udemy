#include <stdlib.h>
#include <stdio.h>

/* Merge is one of the binary operations on arrays (other are append, concat, compare, copy)
Both arrays must be sorted, since the third will contain all the elements in the correct order) */

struct Array
{
    int A[10];
    int length;
    int size;
};

struct Array * merge(struct Array *arr1, struct Array *arr2) // Theta(m+n)
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    int i, j, k;
    i = j = k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        // Comparing the elements from arr1 and arr2 and assigning the lowest to arr3
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            // It assigns and at the same time increments both k and i;
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
            // It assigns and at the same time increments both k and j;
        }
    }
    // Assigning the remaining element
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;

}

void display(struct Array *arr)
{
    for (int i = 0; i < arr->size; i++)
    {
        printf("%d ", arr->A[i]);
    }
    printf("\n");
}

int main(void)
{
    struct Array arr1 = {{3, 8, 16, 20, 25}, 5, 10};
    struct Array arr2 = {{4, 10, 12, 22, 23}, 5, 10};
    struct Array *arr3;

    arr3 = merge(&arr1, &arr2);

    display(arr3);

    return 0;
}
