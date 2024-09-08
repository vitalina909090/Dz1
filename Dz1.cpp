#include <iostream>
#include <Windows.h>
#include <vector>
#include "Fraction.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice, choice2 = 1;

    cout << "\nЯку математичну дію бажаєте виконати?\n[1]Додавання\n[2]Віднімання\n[3]Множення\n[4]Ділення\n";
    cin >> choice;

    Fraction num1, num2;
    cout << "Введіть перший дріб: \n";
    num1.input();
    cout << "Введіть другий дріб: \n";
    num2.input();

    vector<Fraction> fractions;
    fractions.push_back(num1);
    fractions.push_back(num2);

    do {
        cout << "Додати ще один дріб? [1]-так [0]-ні: ";
        cin >> choice2;

        if (choice2 == 1) {
            Fraction additional;
            cout << "Введіть додатковий дріб: \n";
            additional.input();
            fractions.push_back(additional);
        }

    } while (choice2 == 1);

    Fraction result = fractions[0];

    for (int i = 1; i < fractions.size(); i++) {
        switch (choice) {
        case 1:
            result = result.addition(fractions[i]);
            break;
        case 2:
            result = result.subtraction(fractions[i]);
            break;
        case 3:
            result = result.multiplication(fractions[i]);
            break;
        case 4:
            result = result.division(fractions[i]);
            break;
        default:
            cout << "Помилка" << endl;
            return 1;
        }
    }

    cout << "Результат: ";
    result.output();

    return 0;
}