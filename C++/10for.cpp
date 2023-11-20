#include <array>
#include <iostream>
#include <vector>

using namespace std;
const int ArSize = 16;

int main()
{

    long long foactorials[ArSize];

    foactorials[1] = foactorials[0] = 1;

    for (int i = 2;i<ArSize;i++)
    {
        foactorials[i] = i * foactorials[i - 1];
    }

    for (int i = 0; i < ArSize; i++)
    {
        std::cout << i << "!  = " << foactorials[i] << std::endl;
    }

    cout << "Enter a word: ";
    string word;
    cin >> word;

    for (int i = word.size()-1; i >=0; i--)
    {
        cout << word[i];
    }

    int guests = 1;
    while (guests++ < 10)
    {
        /* code */ cout << guests << endl;
    }
    
    

    return 0;
}