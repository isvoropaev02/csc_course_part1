#include <algorithm> // std::swap
#include <cstddef>   // size_t
#include <cstring>   // strlen, strcpy
#include <iostream>

struct String
{
    // constructor 1
    explicit String(const char *str = "")
    {
        this->size = strlen(str);
        char *temp = new char[size + 1];
        strcpy(temp, str);
        temp[size] = '\0';
        this->str = temp;
    }
    // constructor 2
    explicit String(size_t n, char c)
    {
        this->size = n;
        char *temp = new char[size + 1];
        for (size_t i = 0; i < n; i++)
        {
            temp[i] = c;
        }
        temp[size] = '\0';
        this->str = temp;
    }
    // copy constructor
    String(String const &other)
    {
        this->size = other.size;
        this->str = new char[size + 1];
        // std::memcpy(this->str, other.str, size + 1); // можно так, а можно и в лоб
        for (size_t i = 0; i < size + 1; i++)
        {
            str[i] = other.str[i];
        }
        std::cout << "Copy constructor called"
                  << "\n";
    };
    // operator=
    String &operator=(const String &other)
    {
        if (this != &other)
        {
            delete[] str;
            this->size = other.size;
            this->str = new char[size + 1];
            for (size_t i = 0; i < size + 1; ++i)
            {
                str[i] = other.str[i];
            }
        }
        return *this;
    }
    // destructor
    ~String()
    {
        delete[] str;
    }

    /* Реализуйте этот метод. */
    void append(String &other)
    {
        char *temp = new char[size + other.size + 1];
        strcpy(temp, str);
        strcpy(temp + size, other.str);
        delete[] str;
        temp[size + other.size] = '\0';
        this->str = temp;
        this->size = size + other.size;
    }
    // методы вызова символа
    char &at(size_t idx)
    {
        std::cout << "Non-const called" << "\n";
        return str[idx];
    }
    char at(size_t idx) const
    {
        std::cout << "Const called" << "\n";
        return str[idx];
    }

    size_t size;
    char *str;
};
