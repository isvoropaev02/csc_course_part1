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

struct ScopedPtr
{
    // реализуйте следующие методы:
    //
    explicit ScopedPtr(Expression *ptr = 0) : ptr_(ptr) {}
    ~ScopedPtr() { delete ptr_; }
    Expression *get() const { return this->ptr_; }
    Expression *release()
    {
        Expression *result = ptr_;
        ptr_ = 0;
        return result;
    }
    void reset(Expression *ptr = 0)
    {
        delete ptr_;
        ptr_ = ptr;
    }
    Expression &operator*() const { return *ptr_; }
    Expression *operator->() const { return ptr_; }

private:
    // запрещаем копирование ScopedPtr
    ScopedPtr(const ScopedPtr &);
    ScopedPtr &operator=(const ScopedPtr &);

    Expression *ptr_;
};

int main()
{
    Number *expr = new Number(4);
    Number *expr2 = new Number(5);
    BinaryOperation *oper = new BinaryOperation(new Number(3), '-', new Number(2));
    return 0;
}
