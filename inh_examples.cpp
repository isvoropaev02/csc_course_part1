# include <iostream>

static int tre = 0;

class Base
{
private:
    virtual void print(){
        std::cout << 1 << "\n";
    }
protected:
    int num;
};

class Child1 : private Base{
public:
    void print(){
        std::cout << 2 << "\n";
        this->num = 6;
    }
};

class Child2 : private Child1{

};

int main()
{
    Child1 g;
    g.print();
    return 0;
}

