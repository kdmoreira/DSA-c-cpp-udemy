#include <stdio.h>
#include <stdlib.h>

/* Drawbacks of Queue using Arrays:
1. Cannot use spaces of deleted elements;
2. Every location can be used only once;
3. The queue could be considered empty and full at the same time;

Solutions:
1. Reset pointers by reinitializing them to -1 when front == rear, but it doesn't guarantee
the use of free spaces if they never come to be equal;
2. Circular queue, a better solution: front and rear will start from 0 (not -1 as done previously)
and with an insertion the element should be placed to index 1, index 0 should be left empty.
When rear == size - 1, if there have been dequeued elements, check if 0 is empty (but the front
pointer mustn't be pointing at 0, since where it points to must always be empty) and if so, enqueue
the new element in the "beginning" of the array, thus the "circular". This is done using a modulo
operation: rear = (rear + 1) % size

*/

int main(void)
{
    return 0;
}


