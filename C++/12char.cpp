#include <array>
#include <iostream>
#include <vector>

using namespace std;
const int ArSize = 16;

int main()
{
    string word = "?ate";
    for (char ch = 'a';word != "mate";ch++) 
    {
        cout<<word<<endl;
        word[0] = ch;
    }

    cout <<"123123"<<word<<endl;

    return 0;
}