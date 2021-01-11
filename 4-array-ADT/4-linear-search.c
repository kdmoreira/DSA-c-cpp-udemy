#include <stdlib.h>
#include <stdio.h>

struct Array
{
    int A[10];
    int length;
    int size;
};

/* Search a unique element (key) in the array and return its index
Best case: O(1), worst case: O(n), average case: O(n), since its a
sum of all elements (n(n+1)/2)/n, which is a 1st degree polynomial n+1/2 */
int search(struct Array arr, int key)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == key)
        {
            return i;
        }
    }
    return -1;
}

// Improved linear search: these reduce the time taken during the next search

int swap(int *x, int *y) // This function will be necessary
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Transposition: moves the key element one position closer to the beginning of the list
int search_transp(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key)
        {
            swap(&arr->A[i-1], &arr->A[i]);
            return i;
        }
    }
    return -1;
}

// Move to front/head: the key element goes to the beginning of the array after it's found
int search_mtf(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key)
        {
            swap(&arr->A[0], &arr->A[i]);
            return i;
        }
    }
    return -1;
}

void display(struct Array arr)
{
    for (int i = 0; i < arr.size; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

int main(void)
{
    struct Array arr = {{8, 9, 4, 7, 6, 3, 10, 5, 14, 2}, 10, 10};

    printf("%d\n", search(arr, 5)); // Returns 7
    display(arr);
    printf("%d\n", search_transp(&arr, 5)); // Returns 7
    display(arr);
    printf("%d\n", search_mtf(&arr, 5)); // Returns 6 since search_transp moved the key
    display(arr);
    printf("%d\n", search(arr, 5)); // Returns 0 since search_mtf moved the key

    return 0;
}
