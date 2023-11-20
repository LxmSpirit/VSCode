#include <array>
#include <ctime>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


int main()
{
    char automoblie[50];
    int year;
    double a_price;
    double d_price;

    ofstream outFile;
    outFile.open("carinfo.txt");

    cout << "Enter the make and model of automobile:";
    cin.getline(automoblie, 50);
    cout << "Enter the model year:";
    cin >> year;
    cout << "Enter the original asking price:";
    cin >> a_price;
    d_price = 0.913 * a_price;

    cout << fixed;//可以使用另一个流操作符 fixed，它表示浮点输出应该以固定点或小数点表示法显示
    cout.precision(2);//precision就是精度，表示输出多少小数位
    cout.setf(ios_base::showpoint);//设置输出格式
    cout << "Make and model:" << automoblie << endl;
    cout << "Year:" << year << endl;
    cout << "Was asking $" << a_price << endl;
    cout << "Now asking $" << d_price << endl;

    outFile << fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile << "Make and model:" << automoblie << endl;
    outFile << "Year:" << year << endl;
    outFile << "Was asking $" << a_price << endl;
    outFile << "Now asking $" << d_price << endl;

    outFile.close();
    

    return 0;
}