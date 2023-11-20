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
    // cout << "Enter character; enter # to quit:\n";
    // cin >> ch;
    cin.get(ch);
    while (cin.fail() == false)//while(cin)
    {
        cout << ch;
        count++;
        cin.get(ch);
    }

    // cin 忽略空格和换行符
    cout << endl
         << "count:" << count << " " << endl;

    return 0;
}