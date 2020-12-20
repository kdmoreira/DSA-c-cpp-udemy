#include <iostream>
using namespace std;

struct Rectangle
{
    int lenght;
    int breadth;
};

int area(Rectangle r) // In C, "struct" before Rectangle is mandatory
{
    return r.lenght * r.breadth;
}

int perimeter(Rectangle r)
{
    return 2 * (r.lenght + r.breadth);
}

// By address since it will modify the actual rectangle
void initialize(Rectangle *r, int lenght, int breadth)
{
    r->lenght = lenght;
    r->breadth = breadth;
}
int main()
{
    Rectangle r1 = {0, 0};
    cout << "Enter lenght and breadth: ";
    cin >> r1.lenght >> r1.breadth;

    int a = area(r1);
    int p = perimeter(r1);
    cout << "Area is " << a << " and perimeter is " << p << endl;

    Rectangle r2; // Initializing a different Rectangle
    int l, b;
    cout << "Enter lenght and breadth: ";
    cin >> l >> b;
    initialize(&r2, l, b); // Call by address
    cout << "Lenght is " << r2.lenght << " and breadth is " << r2.breadth << endl;

    return 0;
}
