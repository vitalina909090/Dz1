#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

class Fraction {
// за замовчуванням приватна інформація
    int numerator; //чисельник
    int denominator; //знаменник

public: 
    // ввід
    void input() {
        cout << "Введіть чисельник: ";
        cin >> numerator;
        do {
            cout << "Введіть знаменник (0 - не можна): ";
            cin >> denominator;
            if (denominator == 0) {
                cout << "Помилка" << endl;
            }
        } while (denominator == 0);
    }
    // вивід
    void output() {
        cout << numerator << "/" << denominator << endl;
    }

};

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
