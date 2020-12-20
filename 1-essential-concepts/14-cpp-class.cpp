#include <iostream>
using namespace std;

class Rectangle
{
private:
    int lenght;
    int breadth;

public:
    Rectangle(){lenght = breadth = 1;} // Default constructor
    Rectangle(int l, int b); // Parameterized constructor
    area(); // Facilitator
    perimeter(); // Facilitator
    int getLenght(){return lenght;} // Accessor
    int getBreadth(){return breadth;} // Accessor
    void setLenght(int l){lenght = l;} // Mutator
    void setBreadth(int b){breadth = b;} // Mutator
    ~Rectangle(); // Destructor
};

// Use a scope resolution operator to implement functions outside of the class
Rectangle::Rectangle(int l, int b) // A constructor is not mandatory, but it's good style
{
    lenght = l;
    breadth = b;
}
int Rectangle::area()
{
    return lenght * breadth;
}
int Rectangle::perimeter()
{
    return 2 * (lenght + breadth);
}
Rectangle::~Rectangle()
{
    // Nothing to destroy in this case, could have left it blank
    cout << "Destructor";
}

int main()
{
    Rectangle r(10, 5);
    cout << "Area is " << r.area() << endl;
    cout << "Perimeter is " << r.perimeter() << endl;
    r.setLenght(20);
    cout << r.getLenght() << endl;

    /* When the function ends, the destructor will be automatically
    called because the object is going outside the scope, the object
    will be destroyed */
}
