#include <stdio.h>
#include <stdlib.h>

struct Array {

    int *A;
    int size;
    int length;
};

void display(struct Array arr) {

    printf("Your array consists of: ");
    for (int i = 0; i < arr.size; i++) {
        printf("%d ", arr.A[i]);
    }
}

int main(void) {

    struct Array arr;
    printf("Enter the size of the array: ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size*sizeof(int));
    arr.length = 0; // Because there are no elements

    // Adding elements
    int n, i;
    printf("How many numbers? ");
    scanf("%d", &n);

    printf("Enter all elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr.A[i]);
    }
    arr.length = n; // Since now the length equals the n of elements

    display(arr);

    return 0;
}
