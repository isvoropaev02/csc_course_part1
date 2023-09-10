#include <cstddef> // size_t
#include <iostream>
#include <cstring>

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

    //  operator[i][j]
    class Proxy
    {
    public:
        Proxy(char *initial, int index1) : initial(initial), start_pos(initial + index1) {}

        String const operator[](int index2)
        {
            char *end_pos = initial + index2;
            char *s_cut = new char[int(end_pos - start_pos) + 1];
            for (int ind = 0; ind < int(end_pos - start_pos); ++ind)
            {
                s_cut[ind] = start_pos[ind];
            }
            s_cut[int(end_pos - start_pos)] = '\0';
            String res(s_cut);
            delete[] s_cut;
            return res;
        }

    private:
        char *initial;
        char *start_pos;
    };

    Proxy operator[](int index) const
    {
        return Proxy(str, index);
    }

public:
    size_t size;
    char *str;
};

int main()
{
    String const hello("hello");
    String const hell = hello[0][4]; // теперь в hell хранится подстрока "hell"
    String const ell = hello[1][4];  // теперь в ell хранится подстрока "ell"
    return 0;
}
