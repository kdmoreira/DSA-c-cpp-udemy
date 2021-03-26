#include <stdio.h>
#include <stdlib.h>

#include "chains.h" // Contains: Node, sorted_insert and search

/* Hashing is mainly used for searching.
Advantages:
Compared to linear search, which is O(n), and binary search, which is O(log n),
hashing has a better time complexity since it could be O(1) depending on the technique.
For example, going to an index that is the same as the key you're looking for:
key: 18, then go to A[18].
Drawbacks:
Suppose the only values being stored are 3, 5, 18, this means that an array of size 19
would be needed even if occupied by three elements only, each at the index of the same number.
This is why hashing techniques exist.

Relational mappings:
one to one (function)
one to many (not a function)
many to one (function)
many to many (not a function)

We'll use functions for mapping:
One to one (ideal hashing, O(1)):
Each key go to its corresponding index, e.g: 4 goes to A[4].
That is: h(x) = x
Drawback: too much space required. Option: many to one.

Many to one:
Modulus hash function, e.g: h(x) = x % 10
Drawback: Collision, two keys could be mapped at the same index, for example,
15 and 25 would both go to A[5], since 15%10 = 5 and 25%10 = 5.
Solution: Open Hashing and Closed Hashing (Open Addressing by 1.linear probing or
2.quadratic probing or 3.double hashing). */

/* Chaining:
A hash table made of an array of linked lists, each index being a pointer to a sorted LL.
Analysis: always done considering the loading factor, not the number of elements like other DS.
Take: n elements in an array of some size, suppose n = 100 and size = 100.
Loading factor: lambda = n/size, in the example: 100/10 = 10, the loading factor is 10.
It means that at each location there are approx. 10 keys.
Avg. successful search time:  t = 1 + lambda/2, it means: 1 for the hash function + the avg. number
of elements inside a linked list.
Avg. unsuccessful search time: t = 1 + lambda
Deleting: similar to deleting a node from a LL, first search then when it's found, delete it.

It's possible to modify the hash function. h(x) = x % 10 takes the last digit into consideration.
To take the second-to-last digit: h(x) = (x%10)%10
It's important to select a hash function such that the keys are uniformly distributed. You must have
an idea about the keys you're going to work with in order to choose the appropriate hash function.

*/

int hash(int key, int size)
{
    return key % size;
}

void insert(struct Node *HT[], int key, int size)
{
    int index = hash(key, size);
    sorted_insert(&HT[index], key);
}

void display(struct Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(void)
{

    // Creating a Hash Table and adding elements

    int size = 10;
    struct Node *HashTable[size]; // Array of pointers
    int i;

    for (i = 0; i < size; i++) // Initializing the Hash Table to NULL
    {
        HashTable[i] = NULL;
    }

    insert(HashTable, 12, size);
    insert(HashTable, 22, size);
    insert(HashTable, 42, size);

    // Searching

    struct Node *temp;
    // Using the function has as Hash Table's index with some key
    temp = search(HashTable[hash(22, size)], 22);

    printf("%d \n", temp->data);

    display(HashTable[2]);

    return 0;
}
