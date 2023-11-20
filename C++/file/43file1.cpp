#include <array>
#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
#include "coordin.h"

using namespace std;


int main()
{
    rect rplace;
    polar pplace;

    cout << "Enter the x and y values";

    while(cin >> rplace.x >> rplace.y)
    {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers";
    }

    cout << "Bye!\n";

    return 0;
}
//需要多文件的 到.vscode settings.json中修改

