#pragma once

class Fraction {
private:
    int numerator;
    int denominator;

    int biggest(int a, int b);

public:
    Fraction(int numeratorP, int denominatorP);
    Fraction();

    void input();
    void output();
    Fraction& addition(const Fraction& other);
    Fraction& subtraction(const Fraction& other);
    Fraction& multiplication(const Fraction& other);
    Fraction& division(const Fraction& other);

    Fraction& additionInteger(int integer);
    Fraction& subtractionInteger(int integer);
    Fraction& multiplicationInteger(int integer);

    void reduction();
    void maximumReduction(); 
};
