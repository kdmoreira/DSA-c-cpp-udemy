#include <stdio.h>
#include <stdlib.h>

/* The condition to do a binary search is that the array must be sorted.
Time complexity: best case O(1), worst case O(log n), since it's a successive division.
Taking, for example, an array with 16 elements: 16 = 2^4 -> 4 = log2 16 -> log2 n
An array with 15 elements would be log2 (n+1)
Average case (total time taken by all the possible cases, divided by the num of cases): log n */

struct Array
{
    int A[15];
    int length;
    int size;
};

// Iterative version of a binary search
int b_search(struct Array arr, int key)
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

// Recursive version of a binary search, this is a tail recursion
int b_search_rec(struct Array arr, int key, int lower, int higher)
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
            return b_search_rec(arr, key, lower, middle - 1);
        }
        else
        {
            return b_search_rec(arr, key, middle + 1, higher);
        }
    }
    return -1;
}

int main(void)
{
    struct Array arr = {{4, 8, 10, 15, 18, 21, 24, 27, 29, 33, 34, 37, 39, 41, 43}, 15, 15};

    printf("%d\n", b_search(arr, 18));

    printf("%d\n", b_search_rec(arr, 18, 0, arr.length - 1));

    return 0;
}
