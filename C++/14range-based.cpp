#include <array>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;
const int ArSize = 16;

int main()
{

    double prices[5] = {4.99, 10.99, 6.87, 7.99, 8.49};
    for (double x : prices)
    {
        cout << x << endl;
    }

    
    for (double x : prices)
    {
        x = x * 0.8;
    }


    for (double x : prices)
    {
        cout << "~~~" << x << endl;
    }



    //修改数组元素
    for (double &x : prices)
    {
        x = x * 0.8;
        //cout << "0.8:  " << x << endl;
    }
    
    for (double x : prices)
    {
        cout << "0.8:  " << x << endl;
    }

    return 0;
}