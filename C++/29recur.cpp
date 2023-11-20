#include <array>
#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void countdown(int n);
int countdown2(int n);

int main()
{
    countdown(4);
    int res = countdown2(4);
    cout << "res..." << res << endl;

    return 0;
}

void countdown(int n)
{
    cout << "Counting down..." << n << endl;

    if (n > 0)
    {
        countdown(n - 1);
    }

    cout << n << " : Kaboom!\n";
}

int countdown2(int n)
{

    if (n > 0)
    {
        return n + countdown2(n - 1);
    }
    else
    {
        return n;
    }
}
