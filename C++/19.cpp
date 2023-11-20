#include <array>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;
const int ArSize = 16;

int main()
{
    char cities[5] = {
        'A',
        'B',
        'C'


    };

    char *cities2[5] = {
        "A",
        "B",
        "C"


    };


    for (size_t i = 0; i < 5; i++)
    {
        /* code */
        cout << cities[i] << endl;
    }
    

    return 0;
}