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

    int get_numerator() const { return this->numerator_; }
    int get_denominator() const { return this->denominator_; }

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
    operator double() const { return this->to_double(); }

private:
    int numerator_;
    int denominator_;
};

Rational operator+(Rational left, Rational const &right) { return left += right; }

Rational operator-(Rational left, Rational const &right) { return left -= right; }

Rational operator*(Rational left, Rational const &right) { return left *= right; }

Rational operator/(Rational left, Rational const &right) { return left /= right; }

bool operator==(const Rational &left, const Rational &right)
{
    return (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator());
}

bool operator!=(const Rational &left, const Rational &right) { return !(left == right); }

bool operator<(const Rational &left, const Rational &right)
{
    return (left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator());
}

bool operator>(const Rational &left, const Rational &right) { return right < left; }

bool operator<=(const Rational &left, const Rational &right) { return !(right < left); }

bool operator>=(const Rational &left, const Rational &right) { return !(left < right); }
