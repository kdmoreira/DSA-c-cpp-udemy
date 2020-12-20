#include <iostream>
using namespace std;

// Since it's now a class, all its members are private
class Rectangle // If it were a struct, the members would be public
{
public: // You have to make it public so that they're directly accessible
    int lenght;
    int breadth;

    void initialize(int l, int b)
    {
        lenght = l;
        breadth = b;
    }
    int area()
    {
        return lenght * breadth;
    }

    int perimeter()
    {
        return 2 * (lenght + breadth);
    }
};

int main()
{
    Rectangle r;
    int l, b;
    cout << "Enter lenght and breadth: ";
    cin >> l >> b;
    r.initialize(l, b);

    int a = r.area();
    int p = r.perimeter();
    cout << "Area is " << a << " and perimeter is " << p << endl;

    return 0;
}
