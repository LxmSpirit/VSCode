#include <iostream>
// Program for illustration purposes only: It is bad style for a function
// to use a global variable and also define a local variable with the same name
using namespace std;
int reused = 42; // reused has global scope
int main()
{
    // int unique = 0; // unique has block scope
    // output #1: uses global reused; prints 42 0
    // std::cout << reused << " " << unique << std::endl;
    // int reused = 0; // new, local object named reused hides global reused
    // // output #2: uses local reused; prints 0 0
    // std::cout << reused << " " << unique << std::endl;
    // // output #3: explicitly requests the global reused; prints 42 0
    // std::cout << ::reused << " " << unique << std::endl;

    int i = 42;
    int *p;      // p is a pointer to int
    int *&r = p; // r is a reference to the pointer p
    r = &i;      // r refers to a pointer; assigning &i to r makes p point to i


    cout << "p  "<< p << " " << endl;
    cout << "*p   "<< *p << " " << endl;
    cout << "r   "<< r << " " << endl;
    cout << "*r   "<< *r << " " << endl;

    *r = 0;      // dereferencing r yields i, the object to which p points; changes i to 0

    return 0;
}