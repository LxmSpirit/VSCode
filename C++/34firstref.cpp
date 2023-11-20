#include <array>
#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;



int main()
{
    int rats = 101;
    int &rodents = rats; // 相当于 int * const pr = &rats;

    cout << "rats = " << rats;
    cout <<" , rodents = " << rodents <<endl;
    rodents++;
    cout << "rats = " << rats;
    cout << ", rodents = "<<rodents <<endl;

    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents <<endl;

    return 0;
}

