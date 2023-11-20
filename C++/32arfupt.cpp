#include <array>
#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// 使用typedef 声明函数指针类型的别名
// typedef const double *(*p_fun)(const double *, int);
// p_fun p1 = f1;

const double *f1(const double *ar, int n);
const double *f2(const double ar[], int n);
const double *f3(const double ar[], int n);

int main()
{
    double av[3] = {1112.3, 1542.6, 227.9};

    const double *(*p1)(const double *, int) = f1; // 指向函数的指针
    auto p2 = f2;                                  // 相当于 const double *(*p2)(const double *, int) = f2

    cout << "Using pointers to functions:\n";
    cout << "Address Value\n";
    cout << (*p1)(av, 3) << ":" << *(*p1)(av, 3) << endl;
    cout << p2(av, 3) << ":" << *p2(av, 3) << endl;

    const double *(*pa[3])(const double *, int) = {f1, f2, f3}; // 存放函数指针的数组
    auto pb = pa;                                               // auto 对于list不适用，pb仅仅是指向pa第一个元素的指针
                                                                // 相当于 const double *(**pb)(const double *, int) = pa

    cout << "\n Using an array of pointers to functions:\n";
    cout << "Address Value\n";
    for (int i = 0; i < 3; i++)
    {
        cout << pa[i](av, 3) << ":" << *pa[i](av, 3) << endl;
    }

    cout << "\n Using a pointer to a pointer to a function:\n";
    cout << "Address Value\n";
    for (int i = 0; i < 3; i++)
    {
        cout << pb[i](av, 3) << ":" << *pb[i](av, 3) << endl;
    }

    cout << "\n Using a pointer to an array of function pointers:\n";
    cout << "Address Value\n";
    auto pc = &pa; // 相当于 const double *( *(*pc)[3] )(const double *, int) = &pa;
    cout << (*pc)[0](av, 3) << ":" << *(*pc)[0](av, 3) << endl;
    const double  *(*(*pd)[3])(const double *, int) = &pa;
    const double *pdb = (*pd)[1](av, 3);
    cout << pdb << ":" << *pdb << endl;

    cout << (*(*pd)[2])(av, 3) << ":" << *(*(*pd)[2])(av, 3) << endl;

    return 0;
}

const double *f1(const double *ar, int n)
{
    return ar;
}

const double *f2(const double ar[], int n)
{
    return ar + 1;
}

const double *f3(const double ar[], int n)
{
    return ar + 2;
}
