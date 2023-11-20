#include <array>
#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void file_it(ostream &os, double fo, const double fe[], int n);
const int LIMIT = 5;

int main()
{
    ofstream fout;
    const char *fn = "ep-data.txt";
    fout.open(fn);
    if( ! fout.is_open() )
    {
        cout << "Can't open" << fn << ".Bye.\n";
        exit(EXIT_FAILURE);
    }

    double objective;
    cout << "Enter the focal length of your"
            "telescope objective in mm:";
    cin >> objective;
    double eps[LIMIT];
    cout << "Enter the focal length, in mm, of" << LIMIT
         << "eyepieces:\n";
        
    for(int i = 0; i < LIMIT; i++)
    {
        cout << "Eyepiece #" << i + 1 << ":";
        cin >> eps[i];
    }

    file_it(fout, objective,eps,LIMIT);
    file_it(cout, objective,eps,LIMIT);
    cout << "Done!\n";

    return 0;
}

void file_it(ostream &os, double fo, const double fe[], int n)
{
    ios_base::fmtflags initial;
    initial = os.setf(ios_base::fixed); //将对象置于使用定点表示法的模式
    os.precision(0);
    os << "Focal length of objective:" << fo << "mm\n";
    os.setf(ios::showpoint); //将对象置于显示小数点的模式
    os.precision(1);// 指定显示多少位小数，假定对象处于定点模式下
    os.width(12); //设置下一次输出操作使用的字段宽度，只在显示下一个值时有效
    os << " magnification " << endl;

    for (int i = 0; i < n; i++)
    {
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int(fo / fe[i] + 0.5) << endl;
    }

    os.setf(initial);//将对象回到传递给file_it()之前的状态
}
