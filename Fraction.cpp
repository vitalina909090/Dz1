#include "Fraction.h"
#include <iostream>
using namespace std;

void Fraction :: input() {
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

void Fraction::output() {
    cout << numerator << "/" << denominator << endl;
}