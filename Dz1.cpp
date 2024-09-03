#include <iostream>
#include <Windows.h>
#include <vector>
#include "Fraction.h"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Fraction> myfractions; 
    char choice;

    do {
        Fraction object;
        object.input();
        myfractions.push_back(object);

        cout << "Додати ще один дріб? [1]-так [0]-ні: ";
        cin >> choice;
    } while (choice == '1');

    cout << "\nВведені дроби:\n";
    for (int i = 0; i < myfractions.size(); i++) {
        myfractions[i].output();
    }
}


