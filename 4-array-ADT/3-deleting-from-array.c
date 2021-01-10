#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;

};

// Delete: deleting and returning element from a given index
int delete_element(struct Array *arr, int index) // O(n)
{
    if (index >= 0 && index < arr->length)
    {
        int x = arr->A[index]; // Element to be returned

        /* Using i <= arr->length will copy the 0 inside the next free space into the
        space that used to store the last element */
        for (int i = index; i <= arr->length; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return 0;
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
    struct Array arr = {{8, 3, 7, 12, 15, 6, 9, 10}, 10, 8};

    display(arr);

    printf("%d\n", delete_element(&arr, 3));

    display(arr);

    return 0;

}
