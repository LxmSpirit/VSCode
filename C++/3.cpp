#include <iostream>
using namespace std;

class Base
{
public:
    void show();

protected:
    int aa;
    double dd;
};
void Base::show()
{
}
class Person : public Base
{
public:
    using Base::aa; // 将基类的protected成员变成public
    using Base::dd; // 将基类的protected成员变成public

    void printfa()
    {
        cout << this->aa <<"|||" <<this->dd << endl;
    }

private:
    using Base::show; // 将基类的public成员变成private
    string name;
};

int main()
{
    Person *p = new Person();
    p->aa = 12;
    p->dd = 12.3;
    // p->show();//出错
    // delete p;
    p->printfa();
    return 0;
}