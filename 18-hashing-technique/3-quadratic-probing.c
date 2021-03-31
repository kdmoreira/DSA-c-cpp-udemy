#include <stdio.h>
#include <stdlib.h>

/* Quadratic probing: open addressing, another collision resolution technique.
It's similar to linear probing, but there's a difference:
Linear: h'(x)=(h(x)+f(i))%size where f(i)=1, i=0,1,2...
Quadratic: h'(x)=(h(x)+f(i))%size where f(i)=i^2, i=0,1,2...
This means that elements are stored farther and farther away each time a collision
occurs at a given place.
Analysis:
Avg. successful search: (-log base e(1 - lambda))/lambda
Avg. unsuccessful search: 1/(1 - lambda)
*/

#define SIZE 10

int hash(int key)
{
    return key % SIZE;
}

int probe(int HT[], int key)
{
    int index = hash(key);
    int i = 0;

    // Now it's i*i instead of i
    while (HT[(index + i*i) % SIZE] != 0)
    {
        i++;
    }
    return (index + i*i) % SIZE;
}

void insert(int HT[], int key)
{
    int index = hash(key);
    if (HT[index] != 0)
    {
        index = probe(HT, key);
    }
    HT[index] = key;
}

int search(int HT[], int key)
{
    int index = hash(key);
    int i = 0;

    while (HT[(index + i*i) % SIZE] != key)
    {
        if (HT[(index + i*i) % SIZE] == 0)
        {
            return -1;
        }
        i++;
    }
    return (index + i*i) % SIZE;
}

void display(int HT[])
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", HT[i]);
    }
    printf("\n");
}

int main(void)
{
    int HT[SIZE] = {0};

    insert(HT, 12);
    insert(HT, 25);
    insert(HT, 35);
    insert(HT, 26);
    insert(HT, 45);

    display(HT); // 0 0 12 0 0 25 35 26 0 45

    printf("\nKey found at %d\n", search(HT, 45));

    return 0;
}
