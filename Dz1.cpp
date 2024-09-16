#include <iostream>
#include <Windows.h>
#include <vector>
#include "Fraction.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice, choice2, choice3;
    int integerNum;

    cout << "\nЯку математичну дію бажаєте виконати?\n"
        << "[1] Додавання дробів\n"
        << "[2] Віднімання дробів\n"
        << "[3] Множення дробів\n"
        << "[4] Ділення дробів\n"
        << "[5] Додавання дробу з цілим числом\n"
        << "[6] Віднімання дробу з цілим числом\n"
        << "[7] Множення дробу з цілим числом\n";
    cin >> choice;

    vector<Fraction> fractions;
    vector<int> integers;

    if (choice >= 1 && choice <= 4) {
        cout << "Введіть перший дріб: \n";
        Fraction fraction1;
        fraction1.input();
        fractions.push_back(fraction1);

        cout << "Введіть другий дріб: \n";
        Fraction fraction2;
        fraction2.input();
        fractions.push_back(fraction2);

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
                result.addition(fractions[i]);
                break;
            case 2:
                result.subtraction(fractions[i]);
                break;
            case 3:
                result.multiplication(fractions[i]);
                break;
            case 4:
                result.division(fractions[i]);
                break;
            default:
                cout << "Помилка" << endl;
            }
        }

        cout << "Результат: ";
        result.maximumReduction();
    }
    else if (choice >= 5 && choice <= 7) {
        cout << "Введіть перший дріб: \n";
        Fraction fraction;
        fraction.input();
        fractions.push_back(fraction);

        cout << "Введіть ціле число: ";
        cin >> integerNum;
        integers.push_back(integerNum);

        do {
            cout << "Додати ще один дріб або ціле число? [1]-так [0]-ні: ";
            cin >> choice2;

            if (choice2 == 1) {
                cout << "Що ви хочете додати?\n"
                    << "[1] Дріб\n"
                    << "[2] Ціле число\n";
                cin >> choice3;

                if (choice3 == 1) {
                    Fraction additionalFraction;
                    cout << "Введіть додатковий дріб: \n";
                    additionalFraction.input();
                    fractions.push_back(additionalFraction);
                }
                else if (choice3 == 2) {
                    int additionalInteger;
                    cout << "Введіть додаткове ціле число: \n";
                    cin >> additionalInteger;
                    integers.push_back(additionalInteger);
                }
            }
        } while (choice2 == 1);

        Fraction result = fractions[0];
        for (int i = 1; i < fractions.size(); i++) {
            switch (choice) {
            case 5:
                result.addition(fractions[i]);
                break;
            case 6:
                result.subtraction(fractions[i]);
                break;
            case 7:
                result.multiplication(fractions[i]);
                break;
            }
        }

        for (int i = 0; i < integers.size(); i++) {
            switch (choice) {
            case 5:
                result.additionInteger(integers[i]);
                break;
            case 6:
                result.subtractionInteger(integers[i]);
                break;
            case 7:
                result.multiplicationInteger(integers[i]);
                break;
            }
        }

        cout << "Результат: ";
        result.maximumReduction();
    }
    else {
        cout << "Невірний вибір" << endl;
    }

    return 0;
}
