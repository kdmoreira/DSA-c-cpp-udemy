#include <stdio.h>
#include <stdlib.h>

// Definition with variable declaration
struct Rectangle
{
    int lenght;
    int breadth;
    char x; // Not useful for a rectangle, but it exemplifies a case of padding
} r1;

// Variable declarations outside main
struct Rectangle r2,r3;

int main()
{
    // Variable declaration inside main
    struct Rectangle r4 = {10,5,'a'};

    /* Note that the struct uses 4 bytes for each int and also for x
    even though char takes 1 byte: padding of memory occurs in this case */
    printf("%d\n", sizeof(r4));

    printf("%d\n", r4.lenght);
    printf("%d\n", r4.breadth);
    printf("%c\n", r4.x);

    // Accessing and changing the values of the members directly
    r4.lenght = 5;
    r4.breadth = 7;

    printf("%d\n", r4.lenght);
    printf("%d\n", r4.breadth);

    return 0;
}
