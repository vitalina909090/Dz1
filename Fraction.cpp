#include "Fraction.h"
#include <iostream>
using namespace std;

void Fraction :: input() {
    cout << "������ ���������: ";
    cin >> numerator;
    do {
        cout << "������ ��������� (0 - �� �����): ";
        cin >> denominator;
        if (denominator == 0) {
            cout << "�������" << endl;
        }
    } while (denominator == 0);
}

void Fraction::output() {
    cout << numerator << "/" << denominator << endl;
}