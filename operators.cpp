#include <iostream>

struct Rational
{
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {}

    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const;

    Rational &operator+=(Rational rational)
    {
        this->add(rational);
        return *this;
    }
    Rational &operator-=(Rational rational)
    {
        this->sub(rational);
        return *this;
    }
    Rational &operator*=(Rational rational)
    {
        this->mul(rational);
        return *this;
    }
    Rational &operator/=(Rational rational)
    {
        this->div(rational);
        return *this;
    }
    Rational operator-() const
    {
        Rational tmp(this->numerator_, this->denominator_);
        tmp.neg();
        return tmp;
    }
    Rational operator+() const
    {
        Rational tmp(this->numerator_, this->denominator_);
        return tmp;
    }

private:
    int numerator_;
    int denominator_;
};

Rational operator+(Rational left, Rational const &right) { return left += right; }

Rational operator-(Rational left, Rational const &right) { return left -= right; }

Rational operator*(Rational left, Rational const &right) { return left *= right; }

Rational operator/(Rational left, Rational const &right) { return left /= right; }
