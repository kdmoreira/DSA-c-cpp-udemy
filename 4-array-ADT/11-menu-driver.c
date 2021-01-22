#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// The menu includes all the previous operations upon arrays

struct Array
{
    int *A;
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

void append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
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


int delete_item(struct Array *arr, int index)
{
    int x = 0;
    int i;
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for(i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
            arr->length--;
            return x;
        }
    }
    return 0;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int linear_search(struct Array arr, int key)
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

int binary_search(struct Array arr, int key)
{
    int lower = 0;
    int higher = arr.length - 1;
    while (lower <= higher)
    {
        int middle = (lower + higher) / 2;
        if (arr.A[middle] == key)
        {
            return middle;
        }
        else if (key < arr.A[middle])
        {
            higher = middle - 1;
        }
        else
        {
            lower = middle + 1;
        }
    }
    return -1;
}

int rec_bin_search(struct Array arr, int key, int lower, int higher)
{
    if (lower <= higher)
    {
        int middle = (lower + higher) / 2;
        if (arr.A[middle] == key)
        {
            return middle;
        }
        else if (key < arr.A[middle])
        {
            return rec_bin_search(arr, key, lower, middle - 1);
        }
        else
        {
            return rec_bin_search(arr, key, middle + 1, higher);
        }
    }
    return -1;
}

// Get: retrieves an element at the given index
int get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
    return -1;
}

// Set: replaces a value at a particular index
void set(struct Array *arr, int index, int new_value)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = new_value;
    }
}

// Max: finds the highest number among the elements
int max(struct Array arr) // f(n)=2n+1 -> O(n)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

// Min: finds the smallest number among the elements
int min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

// Sum: sums all elements
int sum(struct Array arr)
{
    int total = 0;
    for (int i = 0; i < arr.length; i++)
    {
        total += arr.A[i];
    }
    return total;
}

// Average: Sum of all elements divided by the number of elements
float average(struct Array arr, int length)
{
    int total = 0;
    for (int i = 0; i < arr.length; i++)
    {
        total += arr.A[i];
    }
    // Average can be even simpler: return sum(arr)/arr.length
    return (float) total / length;
}

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

void insert_sort(struct Array *arr, int key)
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

// Rearrange: negative numbers on the left side and positive on the right
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

struct Array * merge(struct Array *arr1, struct Array *arr2) // Theta(m+n)
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    int i, j, k;
    i = j = k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }
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

// Union: new array with all the elements from A and B, but without duplicates
struct Array * union_sorted(struct Array *arr1, struct Array *arr2) // For sorted arrays
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    int i, j, k;
    i = j = k = 0;
    while (i < arr1->length && j < arr2->length)
    {
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
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
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

// Intersection: the third array contains elements that are shared by A and B
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

// Difference: A - B, this means the third array contains elements from A that aren't in B.
struct Array * difference_sorted(struct Array *arr1, struct Array *arr2) // For sorted arrays
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    int i, j, k;
    i = j = k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if (arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}


int main(void) {

    struct Array arr1;
    int choice, item, index;

    printf("Enter the size of the array: ");
    scanf("%d", &arr1.size);
    arr1.A = (int *)malloc(arr1.size * sizeof(int));

    do
    {
        printf("Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: printf("Enter an item and index: ");
            scanf("%d%d", &item, &index);
            insert(index, item, &arr1);
            break;
            case 5: display(arr1);
        }
    } while (choice < 6);


    return 0;
}
