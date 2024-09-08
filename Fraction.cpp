#include <iostream>
#include "Fraction.h"

using namespace std;

void Fraction::input() {
    cout << "¬вед≥ть чисельник: ";
    cin >> numerator;
    do {
        cout << "¬вед≥ть знаменник (0 - не можна): ";
        cin >> denominator;
        if (denominator == 0) {
            cout << "«наменник не може бути нульовим!" << endl;
        }
    } while (denominator == 0);
}

void Fraction::output() {
    cout << numerator << "/" << denominator;
}

int Fraction::biggest(int a, int b) {
    while (b != 0) {
        int temporary = b;
        b = a % b;
        a = temporary;
    }
    return a;
}

Fraction Fraction::addition(Fraction other) {
    Fraction result;
    result.numerator = numerator * other.denominator + other.numerator * denominator;
    result.denominator = denominator * other.denominator;
    result.reduction();
    return result;
}

Fraction Fraction::subtraction(Fraction other) {
    Fraction result;
    result.numerator = numerator * other.denominator - other.numerator * denominator;
    result.denominator = denominator * other.denominator;
    result.reduction();
    return result;
}

Fraction Fraction::multiplication(Fraction other) {
    Fraction result;
    result.numerator = numerator * other.numerator;
    result.denominator = denominator * other.denominator;
    result.reduction();
    return result;
}

Fraction Fraction::division(Fraction other) {
    Fraction result;
    result.numerator = numerator * other.denominator;
    result.denominator = denominator * other.numerator;
    result.reduction();
    return result;
}

void Fraction::reduction() {
    int division = biggest(numerator, denominator);
    numerator /= division;
    denominator /= division;
}