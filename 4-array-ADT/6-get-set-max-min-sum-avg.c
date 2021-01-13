#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[15];
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

// Recursive sum (n is length - 1)
int sum_rec(struct Array arr, int n)
{
    if (n < 0)
    {
        return 0;
    }
    return sum_rec(arr, n - 1) + arr.A[n];
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

int main(void)
{
    struct Array array1 = {{4, 8, 10, 15, 18, 21, 24, 27, 29, 33, 34, 37, 39, 41, 43}, 15, 15};

    printf("%d\n", get(array1, 2)); // 10

    set(&array1, 2, 11); // array1[2] will be set to 11

    display(array1);

    // Unsorted array
    struct Array array2 = {{8, 3, 9, 15, 6, 10, 7, 2, 12, 4}, 9, 9};

    printf("%d\n", max(array2)); // 15

    printf("%d\n", min(array2)); // 2

    printf("%d\n", sum(array2)); // 72

    printf("%d\n", sum_rec(array2, array2.length - 1)); // 72

    printf("%.2f\n", average(array1, array1.length)); // 25.60

    return 0;
}
