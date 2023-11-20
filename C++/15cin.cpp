#include <array>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;
const int ArSize = 16;

int main()
{
    char ch;
    int count = 0;
    cout << "Enter character; enter # to quit:\n";
    cin >> ch;
    while (ch != '#')
    {
        cout << ch;
        count++;
        cin >> ch;
    }

    //cin 忽略空格和换行符
    cout << "\n count:" <<count << " " << endl;

    return 0;
}