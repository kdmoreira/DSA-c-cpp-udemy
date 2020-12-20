#include <iostream>
using namespace std;

// A template is a generic class that works for any type of data
template <class T>
class Arithmetic
{
private:
    T a;
    T b;

public:
    Arithmetic(T a, T b)
    {
        /* "This" is used to refer to the members of the class
        If it were "a = a" this would mean the formal parameter "a" equals itself */
        this->a = a; // Pointer to a current object
        this->b = b;
    }
    T add()
    {
        T c;
        c = a + b;
        return c;
    }
    T sub();
};
// Defining sub outside of class to demonstrate changes
template <class T> // Must declare again before each function defined outside
T Arithmetic<T>::sub() // Don't forget to add the return type T and <T> before scope resolution
{
    T c;
    c = a - b;
    return c;
}

int main()
{
    Arithmetic<int> ar(5, 10); // The type must be defined
    cout << ar.add() << endl;
    cout << ar.sub() << endl;

    // Now a float type
    Arithmetic<float> ar2(10.99, 5.44);
    cout << ar2.add() << endl;
    cout << ar2.sub() << endl;

    Arithmetic<char> ar3('A', 'B'); // It could work even for chars
    cout << (int)ar3.add() << endl; // Using a typecast
    cout << (int)ar3.sub() << endl;
}
