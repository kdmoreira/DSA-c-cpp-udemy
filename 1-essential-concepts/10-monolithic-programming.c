#include <stdio.h>
#include <stdlib.h>

int main()
{
    int lenght = 0, breadth = 0; // It's a good practice to initialize variables

    printf("Enter lenght and breadth: ");
    scanf("%d %d", &lenght, &breadth); // In C++ you could use: cin >> lenght >> breadth

    int area = lenght * breadth;
    int perimeter = 2 * (lenght + breadth);

    printf("The area is %d and the perimeter is %d", area, perimeter);

    return 0;
}
