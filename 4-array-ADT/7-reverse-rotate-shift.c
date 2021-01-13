#include <stdlib.h>
#include <stdio.h>

struct Array
{
    int A[10];
    int length;
    int size;
};

// Reverse: one of the methods use an auxiliary array, O(n), here it will return the array
struct Array * reverse(struct Array *arr) // void would only modify, but it works too
{
    int *B;
    B = (int *)malloc(arr->length * sizeof(int));
    for (int i = 0, j = arr->length - 1; i < arr->length; i++, j--)
    {
        B[j] = arr->A[i];
    }
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
    return arr;
}

// Reverse: the other method is by swapping the elements
struct Array * reverse_swap(struct Array *arr)
{
    int temp;
    for (int i = 0, j = arr->length - 1; i < arr->length; i++, j--)
    {
        if (i > j)
        {
            break;
        }
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
    return arr;
};

// Left Shift: shifts elements one place to the left (loses value inside index 0)
void left_shift(struct Array *arr)
{
    for (int i = 0; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->length - 1] = 0;
}

// Right Shift: shifts elements one place to the right (loses value inside last index)
void right_shift(struct Array *arr)
{
    for (int i = arr->length - 1; i >= 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = 0;
}

// Left Rotation: shifts elements one place to the left and the first element becomes the last one
void left_rotation(struct Array *arr)
{
    int temp = arr->A[0];
    for (int i = 0; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->length - 1] = temp;
}

// Right Rotation: shifts elements one place to the right and the last one becomes the first
void right_rotation(struct Array *arr)
{
    int temp = arr->A[arr->length - 1];
    for (int i = arr->length - 1; i >= 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = temp;
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
    struct Array arr = {{8, 3, 9, 15, 6, 10, 7, 2, 12, 4}, 10, 10};

    printf("Original array: ");
    display(arr);

    reverse(&arr);

    printf("Reversed: ");
    display(arr);

    reverse_swap(&arr);

    printf("Swapped: ");
    display(arr);

    left_shift(&arr);

    printf("Shifted to the left: ");
    display(arr);

    right_shift(&arr);

    printf("Shifted to the right: ");
    display(arr);

    struct Array arr2 = {{8, 3, 9, 15, 6, 10, 7, 2, 12, 4}, 10, 10};

    printf("Original array: ");
    display(arr2);

    left_rotation(&arr2);

    printf("Rotated to the left: ");
    display(arr2);

    right_rotation(&arr2);

    printf("Rotated to the right: ");
    display(arr2);

    return 0;
}
