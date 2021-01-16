#include <stdlib.h>
#include <stdio.h>

/* Set operations: union, intersection, difference, set membership.
Set membership: similar to search (it verifies if an element belongs to a set), see binary search
for sorted arrays and linear search for non-sorted arrays */

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

/* Intersection: the third array contains elements that are shared by A and B.
Non-sorted arrays: it takes n*n time, O(n^2).
Sorted arrays: similar to merging, theta(m+n), that is, theta(n). */

struct Array * intersection_sorted(struct Array *arr1, struct Array *arr2) // For sorted arrays
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    int i, j, k;
    i = j = k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            i++;
        }
        else if (arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

/* Difference: A - B, this means the third array contains elements from A that aren't in B.
Non-sorted arrays: n*n time, O(n^2).
Sorted arrays: uses merge procedure, theta(m+n), theta(n). */

struct Array * difference_sorted(struct Array *arr1, struct Array *arr2) // For sorted arrays
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    int i, j, k;
    i = j = k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        // Copy elements only from the first array
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if (arr2->A[j] < arr1->A[i])
        {
            j++; // Don't copy from the second, just increment
        }
        else
        {
            // When the elements are equal, don't copy, increment both indexes instead
            i++;
            j++;
        }
    }
    // Remaining elements should be copied only from the first array
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

void display(struct Array *arr)
{
    for (int i = 0; i < arr->length; i++)
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
    struct Array *arr4;
    struct Array *arr5;

    arr3 = union_sorted(&arr1, &arr2);

    display(arr3); // 2 3 6 7 10 15 20 25

    arr4 = intersection_sorted(&arr1, &arr2);

    display(arr4); // 6 15

    arr5 = difference_sorted(&arr1, &arr2);

    display(arr5); // 2 10 25

    return 0;
}
