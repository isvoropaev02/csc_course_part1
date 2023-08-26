#include <iostream>

struct Foo
{
    void say() const { std::cout << "Foo says: " << msg << "\n"; }

protected:
    Foo(const char *msg) : msg(msg) {}

private:
    const char *msg;
};

void foo_says(const Foo &foo)
{
    foo.say();
}

Foo get_foo(const char *msg)
{
    struct Foo_copy : Foo
    {
    public:
        Foo_copy(const char *str) : Foo(str)
        {
        }
    };
    Foo_copy f = Foo_copy(msg);
    Foo_copy * p = &f;
    return f;
}

int main()
{
    foo_says(get_foo("I got U"));
    return 0;
}
