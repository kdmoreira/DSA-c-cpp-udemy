#include <stdlib.h>
#include <stdio.h>

/* Set operations: union, intersection, difference, set membership.

Intersection: only elements that belong to both arrays
Non-sorted arrays: it takes n*n, O(n^2)
Sorted: similar to merging, Theta(m+n), that is, Theta(n)
Difference: e.g. A - B, this means only elements from A that aren't in B.
Non-sorted: n*n, it's O(n^2)
Sorted: uses merge procedure, Theta(m+n), Theta(n)
Set membership: is similar to searching, since it verifies if an element belongs to a set */

struct Array
{
    int A[10];
    int length;
    int size;
};

/* Union: new array with all the elements from A and B, but without duplicates.
Non-sorted arrays: union takes n+n^2 time, that is, O(n^2).
Sorted arrays: union uses merge procedure: theta(m+n), that is, theta(n). */

struct Array * union_sorted(struct Array *arr1, struct Array *arr2) // For sorted arrays
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    int i, j, k;
    i = j = k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        // Comparing the elements from arr1 and arr2 to verify the smallest one
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if (arr2->A[j] < arr1->A[i])
        {
            arr3->A[k++] = arr2->A[j++];
        }
        else
        {
            // Copy from any array (arr1 chosen in this case) and increment all indexes
            arr3->A[k++] = arr1->A[i++];
            j++;
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
    arr3->length = k;
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
    struct Array arr1 = {{2, 6, 10, 15, 25}, 5, 10};
    struct Array arr2 = {{3, 6, 7, 15, 20}, 5, 10};
    struct Array *arr3;

    arr3 = union_sorted(&arr1, &arr2);

    display(arr3);

    return 0;
}
