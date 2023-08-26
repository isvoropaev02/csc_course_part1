#include "final_string_structure copy.hpp"

int main(int argc, char const *argv[])
{
    String greet("Hello");
    std::cout << "1" << "\n";
    char ch1 = greet.at(0);

    String const const_greet("Hello, Const!");
    std::cout << "2" << "\n";
    char const &ch2 = const_greet.at(0);
    ch1 = 'y';
    return 0;
}
