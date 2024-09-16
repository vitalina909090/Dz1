#include <iostream>
#include "Fraction.h"

using namespace std;

Fraction::Fraction(int numeratorP, int denominatorP) : numerator(numeratorP), denominator(denominatorP) {
    reduction();
}

Fraction::Fraction() : Fraction(0, 1) { }

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
    reduction();
}

void Fraction::output(){
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

Fraction& Fraction::addition(const Fraction& other) {
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator = denominator * other.denominator;
    reduction();
    return *this;
}

Fraction& Fraction::subtraction(const Fraction& other) {
    numerator = numerator * other.denominator - other.numerator * denominator;
    denominator = denominator * other.denominator;
    reduction();
    return *this;
}

Fraction& Fraction::multiplication(const Fraction& other) {
    numerator = numerator * other.numerator;
    denominator = denominator * other.denominator;
    reduction();
    return *this;
}

Fraction& Fraction::division(const Fraction& other) {
    numerator = numerator * other.denominator;
    denominator = denominator * other.numerator;
    reduction();
    return *this;
}

Fraction& Fraction::additionInteger(int integer) {
    numerator = numerator + integer * denominator;
    reduction();
    return *this;
}

Fraction& Fraction::subtractionInteger(int integer) {
    numerator = numerator - integer * denominator;
    reduction();
    return *this;
}

Fraction& Fraction::multiplicationInteger(int integer) {
    numerator = numerator * integer;
    reduction();
    return *this;
}

void Fraction::reduction() {
    int division = biggest(numerator, denominator);
    numerator /= division;
    denominator /= division;
}

void Fraction::maximumReduction() {
    int whole = numerator / denominator;
    int remainder = numerator % denominator; 

    if (remainder != 0) { 
        if (whole != 0) {
            cout << whole << " ц≥лих " << remainder << "/" << denominator << endl;
        }
        else { 
            cout << remainder << "/" << denominator << endl;
        }
    }
    else {  
        cout << whole << endl;
    }
}