#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int &r = a; // When a reference is created you must initialize it
    cout << a << endl << r << endl;
    r=25; // Now a and r are 25
    cout << a << endl << r << endl;
    int b = 30;
    r = b; // Now a, r and b are 30
    cout << a << endl << r << endl;

    return 0;
}
