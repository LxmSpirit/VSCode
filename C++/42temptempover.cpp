#include <array>
#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct debts
{
    char name[50];
    double amount;
};

template <typename T>
void ShowArray(T arr[], int n);

template <typename T>
void ShowArray(T *arr[], int n);

int main()
{
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] =
        {
            {"Ima Wolfe", 2400.0},
            {"Ura Foxe", 1300.0},
            {"Iby Stout", 1800.0}};

    double *pd[3];

    for (int i = 0; i < 3;i++)
    {
        pd[i] = &mr_E[i].amount;
    }

    cout << "Listing Mr. E's counts of things:\n";
    ShowArray(things,6);

    cout << "Listing Mr. E's debts:\n";
    ShowArray(pd,3);

    return 0;
}

template <typename T>
void ShowArray(T arr[], int n)
{
    cout << "template A\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void ShowArray(T *arr[], int n)
{
    cout << "template B\n";
    for (int i = 0; i < n; i++)
    {
        cout << *arr[i] << " ";
    }
    cout << endl;
}
