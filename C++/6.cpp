#include <iostream>

using namespace std;

int main(){

// 总之，使用new和delete时，应遵守以下规则。
// 不要使用delete来释放不是new分配的内存。
// 不要使用delete释放同一个内存块两次。
// 如果使用new [ ]为数组分配内存，则应使用delete [ ]来释放。
// 如果使用new [ ]为一个实体分配内存，则应使用delete（没有方括
// 号）来释放。
// 对空指针应用delete是安全的。

int tacos[10] = {5,2,8,4,1,2,2,4,6,8};
int *pt = tacos;
cout << "pt"<<pt << endl;
pt = pt + 1;
cout << "pt+1  "<<pt << endl;
cout << "pt+1  "<<  *pt << endl;
int *pe = &tacos[9];
cout << "pe"<<pe << endl;
pe = pe - 1;
cout << "pe-1  "<<pe  << endl;
cout << "pe-1  "<<  *pe << endl;
//得到两个元素的间隔，仅当两个指针指向同一个数组时
int diff = pe - pt;
cout << "pe - pt  "<<pe - pt << endl;
cout << diff << endl;

}