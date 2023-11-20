#include <array>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;
const int ArSize = 16;

int main()
{

    cout << "Enter the delay time,in seconds:";
    float secs;
    cin >> secs;
    clock_t delay = secs * CLOCKS_PER_SEC;

    cout << "starting \a\n";
    clock_t start = clock();
    while (clock() - start < delay )
        ;
    cout << "done\n";

    return 0;
}