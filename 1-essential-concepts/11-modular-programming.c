#include <stdio.h>
#include <stdlib.h>

int area(int lenght, int breadth)
{
    return lenght * breadth;
}

int perimeter(int lenght, int breadth)
{
    return 2 * (lenght + breadth);
}

int main()
{
    int lenght = 0, breadth = 0; // It's a good practice to initialize variables

    printf("Enter lenght and breadth: ");
    scanf("%d %d", &lenght, &breadth); // In C++ you could use: cin >> lenght >> breadth

    int a = area(lenght, breadth);
    int p = perimeter(lenght, breadth);
    printf("The area is %d and the perimeter is %d", a, p);
    /* Note that it's also possible to use:
    printf("The area is %d and the perimeter is %d", area(lenght, breadth), perimeter(lenght, breadth)); */

    return 0;
}
