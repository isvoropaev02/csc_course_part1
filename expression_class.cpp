#include <iostream>
#include <limits>

struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression() {}
};

struct Number : Expression
{
    Number(double value)
        : value(value)
    {
    }
    double evaluate() const
    {
        return value;
    }

private:
    double value;
};

struct BinaryOperation : Expression
{
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const *left, char op, Expression const *right)
        : left(left), op(op), right(right)
    {
    }
    double evaluate() const
    {
        if (this->op == '+')
        {
            return left->evaluate() + right->evaluate();
        }
        else if (this->op == '-')
        {
            return left->evaluate() - right->evaluate();
        }
        else if (this->op == '*')
        {
            return left->evaluate() * right->evaluate();
        }
        else
        {
            if (right->evaluate() != 0)
            {
                return left->evaluate() / right->evaluate();
            }

            else
            {
                return double(NULL);
            }
        }
    }
    ~BinaryOperation()
    {
        delete left;
        delete right;
    }

private:
    Expression const *left;
    Expression const *right;
    char op;
};

bool check_equals(Expression const *left, Expression const *right)
{
    if (*(size_t *)left == *(size_t *)right)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Number *expr = new Number(4);
    Number *expr2 = new Number(5);
    BinaryOperation *oper = new BinaryOperation(new Number(3), '-', new Number(2));
    std::cout << check_equals(expr, oper) << "\n";
    std::cout << check_equals(expr, expr2) << "\n";

    delete expr;
    delete expr2;
    oper->~BinaryOperation();
    return 0;
}
