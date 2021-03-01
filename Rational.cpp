#include "Rational.h"
#include <iostream>

Rational::Rational() {
    numerator = 1;
    denumerator = 1;
    nan = false;
}

Rational::Rational(int x, int y) {
    numerator = x;
    denumerator = y;
    nan = (y == 0);
}

Rational::Rational(int x) {
    numerator = x;
    denumerator = 1;
    nan = false;
}

Rational::Rational(const Rational& other) {
    numerator = other.numerator;
    denumerator = other.denumerator;
    nan = other.nan;
}

int Rational::gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int Rational::lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

void Rational::print() {
    if(nan)
        std::cout << "<NAN>\n";
    else
        std::cout 
            << numerator
            << "/"
            << denumerator
            << std::endl;
}

void Rational::scan() {
    char a;
    std::cin >> numerator >> a >> denumerator;
    nan = (denumerator == 0);
}

Rational Rational::reduce() {
    int sign = 1;
    if (numerator < 0) {
        sign = -1;
    }
    int del = 1;
    if (!nan) {
        del = gcd(sign * numerator, denumerator);
    }
    return Rational(numerator / del, denumerator / del);
}

Rational Rational::neg() {
    return Rational(
            -1 * numerator,
            denumerator
    );
}

Rational Rational::inv() {
    return Rational(
        denumerator,
        numerator
    );
}

Rational Rational::sum(Rational other) {
    int num1, num2;
    num1 = numerator;
    num2 = other.numerator;
    int newDenum;
    if (denumerator == 0 || other.denumerator == 0) {
        newDenum = 0;
        num1 = 1;
        num2 = 0;
    }
    else {
        newDenum = lcm(denumerator, other.denumerator);
        num1 *= newDenum / denumerator;
        num2 *= newDenum / other.denumerator;
    }
    Rational res(num1 + num2, newDenum);

    return res.reduce();
}

Rational Rational::sub(Rational other) {
    return sum(other.neg());
}

Rational Rational::div(Rational other) {
    return mul(other.inv());
}

bool Rational::eq(Rational r) {
    return 
        numerator == r.numerator
        &&
        denumerator == r.denumerator;
}

bool Rational::l(Rational r) {
    return
        numerator * r.denumerator
        <
        r.numerator* denumerator;
}

bool Rational::leq(Rational r) {
    return
        numerator * r.denumerator
        <=
        r.numerator* denumerator;
}

bool Rational::g(Rational r) {
    return !leq(r);
}

bool Rational::geq(Rational r) {
    return !l(r);
}


bool Rational::neq(Rational r) {
    return !eq(r);
}

Rational Rational::mul(Rational r){
    return Rational(
        numerator * r.numerator,
        denumerator * r.denumerator
    );
}

// inv
// sum/sub/mul/div

int main() {
    Rational x; // 1/1
    Rational y(10, 5); // 10/5
    Rational z(7);

    std::cout << "x.eq(y): ";
    std::cout << x.eq(y) << std::endl;
    std::cout << "x.neq(y): ";
    std::cout << x.neq(y) << std::endl;
    std::cout << "z.neg(): ";
    z.neg().print();

    Rational n(10, 0);
    n.mul(Rational(1)).print();
    Rational(1).mul(n).print();
}
