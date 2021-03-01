#pragma once

class Rational {
public:
 
    bool nan;
    int numerator;
    int denumerator;

    Rational();
    Rational(int, int);
    Rational(int);
    Rational(const Rational& other);

    int gcd(int a, int b);
    int lcm(int a, int b);
    
    Rational reduce();
    Rational neg();
    Rational inv();

    Rational sum(Rational other);
    Rational sub(Rational other);
    Rational mul(Rational other);
    Rational div(Rational other);

    
    bool eq(Rational);
    bool neq(Rational);
    bool l(Rational);
    bool leq(Rational);
    bool g(Rational);
    bool geq(Rational);

    
    void print();
    void scan();
};
