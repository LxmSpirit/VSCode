#include <array>
#include <ctime>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
const int SIZE = 60;

int main()
{
    char filename[SIZE];
    ifstream inFile;

    cout << "Enter name of data file:";
    cin.getline(filename,sizeof(filename));
    inFile.open(filename);
    
    if(!inFile.is_open())
    {
        cout << "Could not open data file" << filename << endl;
        cout << "Program terminated.\n";
        exit(EXIT_FAILURE);
    }

    double value;
    double sum = 0.0;
    int count = 0;

// 例如，程序期望文件中只包含数字。如果最后一
// 次读取操作中发生了类型不匹配的情况，方法fail( )将返回true（如果遇
// 到了EOF，该方法也将返回true）。最后，可能出现意外的问题，如文
// 件受损或硬件故障。如果最后一次读取文件时发生了这样的问题，方法
// bad( )将返回true。不要分别检查这些情况，一种更简单的方法是使用
// good( )方法，该方法在没有发生任何错误时返回true：
    // inFile >> value;
    // while(inFile.good()) 
    // {
    //     ++count;
    //     sum += value;

    //     inFile >> value;
    // }


    while( inFile >> value ) 
    {
        ++count;
        sum += value;   
    }

    if( inFile.eof() )
    {
        cout << "End of file reached.\n";
    }
    else if(inFile.fail())
    {
        cout << "Input terminated by data mismatch.\n";
    }
    else
    {
        cout << "Input terminated for unknown reason.\n";
    }
        
    if(count == 0)
    {
        cout << "No data processed.\n";
    }
    else
    {
        cout << "Items read:" << count << endl;
        cout << "Sum:" << sum << endl;
        cout << "Average:" << sum / count << endl;
    }

    inFile.close();

    return 0;
}