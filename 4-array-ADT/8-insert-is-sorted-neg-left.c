#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Checking if array is sorted, inserting element in a sorted array
struct Array
{
    int A[10];
    int length;
    int size;
};

void insert(struct Array *arr, int key)
{
    if (arr->length == arr->size) // There needs to be at least one vacant space
    {
        return;
    }
    // While loop is useful when you don't know how many times to iterate
    int i = arr->length - 1;
    while (i >= 0 && arr->A[i] > key)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = key;
    arr->length++;
}

// Checks if an array is sorted or not, O(1) if sorted, O(n) if not
bool is_sorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return false;
        }
    }
    return true;
}

// Negative numbers on the left side and positive on the right
void neg_left_side(struct Array *arr) // O(n)
{
   int i = 0;
   int j = arr->length;
   while (i < j)
   {
        while (arr->A[i] < 0)
        {
            i++;
        }
        while (arr->A[j] >= 0)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr->A[i];
            arr->A[i] = arr->A[j];
            arr->A[j] = temp;
        }
   }
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
    struct Array arr = {{4, 8, 13, 16, 20, 25, 28, 33}, 8, 10};

    insert(&arr, 18);

    display(arr);

    struct Array arr2 = {{4, 8, 13, 66, 20, 25, 28, 33}, 8, 10};

    printf("%s\n", is_sorted(arr2) ? "true" : "false");

    struct Array arr3 = {{-6, 3, -8, 10, 5, -7, -9, 12, -4, 2}, 10, 10};

    neg_left_side(&arr3);

    display(arr3);

    return 0;
}
