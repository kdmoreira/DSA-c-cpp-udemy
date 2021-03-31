#include <stdio.h>
#include <stdlib.h>

/* Linear probing: a form of closed hashing, since it will not consume extra space
besides the space available in the hash table, instead it searches for the next free
space to store an element that has collided with another one where it was mapped.
It's based on the hash function: h'(x)=(h(x)+f(i))%size where f(i)=1, i=0,1,2...
The same as using h(x)=x%size and looking for the next free space when there's a collision.

Analysis: it takes more than constant time. The loading factor (lambda = n/size) should
always be <= 0.5, this means that inside an array of size 10, there should be only 5 keys.
Time taken:
Avg. successful search: t = 1 / lambda * natural log(1 / 1-lambda)
Avg. unsuccessful search: t = 1 / 1-lambda

Drawbacks: must keep half of the hash table vacant (waste of space); different keys together
may form a cluster (primary clustering of keys); when deleting keys, a place is left vacant,
if nothing is done with the next keys (that could occupy the space), when searching for a key
that is after the extra space, this would lead to an unsuccessful search since the search stops
after finding a blank space. Since rearranging the keys isn't simple, one solution is called
"rehashing", taking all the keys and inserting them into the hash table once again. Considering
the amount of work, in linear probing we avoid deleting keys, instead, we could put a flag (1 or 0)
to show if the key is there or not (when it should have been deleted).
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
    // Looking for a free space to place the key
    while (HT[(index + i % SIZE)] != 0)
    {
        i++;
    }
    return (index + i) % SIZE;
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
    // Looks for the key
    while (HT[(index + i)%SIZE] != key)
    {
        if (HT[(index + i)%SIZE] == 0) // Empty space, key not found
        {
            return -1;
        }
        i++;
    }
    return (index + i) % SIZE;
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

    display(HT); // 0 0 12 0 0 25 35 26 45 0

    printf("\nKey found at %d\n", search(HT, 45));

    return 0;
}
