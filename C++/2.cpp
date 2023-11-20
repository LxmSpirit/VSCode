#include <iostream>
using namespace std;

#define LENGTH 10 //预处理器


int main()
{
   cout << "Hello\tWorld\n\n";
    int a =10;
    int *b = &a;
    int &c = a;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    a = a + 1;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    c = c + 1;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    return 0;

}