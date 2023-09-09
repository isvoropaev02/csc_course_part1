#include <iostream>
#include <string>

class Number;
class BinaryOperation;

class Visitor
{
public:
    virtual void visitNumber(Number const *number) = 0;
    virtual void visitBinaryOperation(BinaryOperation const *binary) = 0;
    virtual ~Visitor() {}
};

class Expression
{
public:
    virtual double evaluate() const = 0;
    virtual ~Expression() {}
    virtual void visit(Visitor *visitor) const = 0;
};

class Number : public Expression
{
public:
    Number(double value) : value(value) {}
    double evaluate() const { return this->value; }
    double get_value() const { return this->value; }
    void visit(Visitor *visitor) const override { visitor->visitNumber(this); }

private:
    double value;
};

class BinaryOperation : public Expression
{
public:
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const *left, char op, Expression const *right)
        : left(left), op(op), right(right) {}
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
    Expression const *get_left() const { return this->left; }
    Expression const *get_right() const { return this->right; }
    char get_op() const { return this->op; }
    void visit(Visitor *visitor) const override { visitor->visitBinaryOperation(this); }

private:
    Expression const *left;
    Expression const *right;
    char op;
};

class PrintBinaryOperationsVisitor : public Visitor
{
public:
    void visitNumber(Number const *number) override { std::cout << number->get_value(); }

    void visitBinaryOperation(BinaryOperation const *bop) override
    {
        std::cout << "(";
        bop->get_left()->visit(this);
        std::cout << " " << bop->get_op() << " ";
        bop->get_right()->visit(this);
        std::cout << ")";
    }
};

int main()
{
    Expression const *n1 = new Number(5);
    Expression const *n2 = new Number(6);
    Expression const *op = new BinaryOperation(n1, '+', n2);
    Expression const *op2 = new BinaryOperation(n1, '*', op);
    Expression const *op3 = new BinaryOperation(n2, '-', op2);
    PrintBinaryOperationsVisitor visitor;
    op3->visit(&visitor);
    //std::cout << op->evaluate() << "\n";
    return 0;
}
