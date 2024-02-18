#include <iostream>
#include <limits>

//extern int tre = 5;

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


struct SharedPtr
{
    // реализуйте следующие методы:
    //
    explicit SharedPtr(Expression *ptr = 0)
    {
        ps = (ptr != 0) ? (new PtrStruct(ptr)) : 0;
    }
    ~SharedPtr()
    {
        if (ps != 0)
        {
            --(ps->c_);
            if (ps->c_ == 0)
                delete ps;
        }
    }
    SharedPtr(const SharedPtr &ptr)
    {
        this->ps = ptr.ps;
        if (this->ps != 0 && this->ps->c_ != 0)
            ++(this->ps->c_);
    }
    SharedPtr &operator=(const SharedPtr &ptr)
    {
        if (this != &ptr)
        {
            this->~SharedPtr();
            this->ps = ptr.ps;
            if (this->ps != 0)
                ++(this->ps->c_);
        }
    }
    Expression *get() const { return this->ps->ptr_; } // тут возможны проблемы
    void reset(Expression *ptr = 0)
    {
        this->~SharedPtr();
        if(ptr != 0)
            ps = new PtrStruct(ptr);
        else
            ps = 0;
    }
    Expression &operator*() const { return *(this->ps->ptr_); }
    Expression *operator->() const { return (this->ps->ptr_); }

private:
    struct PtrStruct
    {
        PtrStruct(Expression *ptr = NULL)
        {
            this->ptr_ = ptr;
            this->c_ = 1;
        }
        ~PtrStruct()
        {
            delete ptr_;
        }
        Expression *ptr_;
        size_t c_;
    };

    PtrStruct *ps;
};

int main()
{
    Number *expr = new Number(4);
    Number *expr2 = new Number(5);
    BinaryOperation *oper = new BinaryOperation(new Number(3), '-', new Number(2));
    return 0;
}
