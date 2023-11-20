#include <iostream>

int main(){
    using namespace std;
    const int Arsize = 20;
    // char name[Arsize];
    // char dessertp[Arsize];
    // char name2[Arsize];
    // char dessertp2[Arsize];
    char name3[Arsize];
    char dessertp3[Arsize];

    // cout << "name :'\n'";
    // cin >> name;
    // cout << "dessertp :'\n'";
    // cin >> dessertp;
    // //录入A B 会直接输出 通过空白确定字符串结束的位置

    // cout << "name : " << name << "\n";
    // cout << "dessertp : " << dessertp << "\n";

    // cout << "name2 :'\n'";
    // cin.getline(name2,Arsize);
    // cout << "dessertp2 :'\n'";
    // cin.getline(dessertp2,Arsize);
    // //通过回车键保存一行数据

    // cout << "name2 : " << name2 << "\n";
    // cout << "dessertp2 : " << dessertp2 << "\n";

    cout << "name3 :'\n'";
    cin.get(name3,Arsize).get();
    cout << "dessertp3 :'\n'";
    cin.get(dessertp3,Arsize).get();
    //通过回车键保存一行数据

    cout << "name3 : " << name3 << "\n";
    cout << "dessertp3 : " << dessertp3 << "\n";


}