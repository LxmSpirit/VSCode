#include <stdio.h>
#include <iostream>

extern double warming;//使用外部变量warming

void update(double dt);
void local();

using std::cout;

void update(double dt)
{
    extern double warming;//可以省略，指出该函数被设计成使用外部变量

    warming += dt;
    cout << "Updating global warming to " << warming;
    cout << "degress.\n";

}

void local()
{
    double warming = 0.8;//局部变量将隐藏全局变量

    cout << "Local warming = " << warming << "degress.\n";
    cout << "But global warming = " << ::warming;
    cout << "degress.\n";
}
