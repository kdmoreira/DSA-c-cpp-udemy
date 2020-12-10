#include <stdio.h>
#include <stdlib.h>

// definition with variable declaration
struct Rectangle
{
    int lenght;
    int breadth;
    char x;
} r1;

// variable declarations outside main
struct Rectangle r2,r3;

int main(void)
{
    // variable declaration inside main
    struct Rectangle r4={10,5,'a'};

    /* note that the struct uses 4 bytes for each int and also for x
    even though char takes 1 byte: padding of memory occurs in this case */
    printf("%d\n", sizeof(r4));

    printf("%d\n", r4.lenght);
    printf("%d\n", r4.breadth);
    printf("%c\n", r4.x);

    // accessing and changing the values of the members directly
    r4.lenght = 5;
    r4.breadth = 7;

    printf("%d\n", r4.lenght);
    printf("%d\n", r4.breadth);

    return 0;
}
