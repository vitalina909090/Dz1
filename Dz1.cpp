#include <iostream>
#include <Windows.h>
#include <vector>
#include "Fraction.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;
    int integerNum;

    cout << "\nЯку математичну дію бажаєте виконати?\n[1] Додавання дробів\n[2] Віднімання дробів\n[3] Множення дробів\n[4] Ділення дробів\n[5] Додавання дробу з цілим числом\n[6] Віднімання дробу з цілим числом\n[7] Множення дробу з цілим числом\n";
    cin >> choice;

    if (choice >= 1 && choice <= 4) {
        Fraction fraction1, fraction2;
        cout << "Введіть перший дріб: \n";
        fraction1.input();
        cout << "Введіть другий дріб: \n";
        fraction2.input();

        Fraction result;

        switch (choice) {
        case 1:
            result = fraction1.addition(fraction2);
            break;
        case 2:
            result = fraction1.subtraction(fraction2);
            break;
        case 3:
            result = fraction1.multiplication(fraction2);
            break;
        case 4:
            result = fraction1.division(fraction2);
            break;
        default:
            cout << "Помилка" << endl;
        }

        cout << "Результат: ";
        result.maximumReduction();
    }
    else if (choice >= 5 && choice <= 7) {
        Fraction fraction;
        cout << "Введіть дріб: \n";
        fraction.input();

        cout << "Введіть ціле число: ";
        cin >> integerNum;

        Fraction result;

        switch (choice) {
        case 5:
            result = fraction.additionInteger(integerNum);
            break;
        case 6:
            result = fraction.subtractionInteger(integerNum);
            break;
        case 7:
            result = fraction.multiplicationInteger(integerNum);
            break;
        default:
            cout << "Помилка" << endl;
        }

        cout << "Результат: ";
        result.maximumReduction();
    }
    else {
        cout << "Невірний вибір" << endl;
    }

    return 0;
}
