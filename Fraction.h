#pragma once
class Fraction {
private:
    int numerator;
    int denominator;

    int biggest(int a, int b);

public:
    void input();
    void output();
    Fraction addition(Fraction other);
    Fraction subtraction(Fraction other);
    Fraction multiplication(Fraction other);
    Fraction division(Fraction other);
    void reduction();
};