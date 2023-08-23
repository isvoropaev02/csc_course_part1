#include <iostream>
#include "func.hpp"

int main() {
    //print2();
    std::cout <<"bool: " << sizeof(bool) << " bytes" << std::endl; // размеры типов данных
    //std::cout <<"void: " << sizeof(void) << " bytes" << std::endl;
    std::cout <<"unsigned: " << sizeof(unsigned) << " bytes" << std::endl;
    int d = 4;
    std::cout <<"int: " << sizeof(int) << " bytes" << std::endl;
    std::cout <<"short int: " << sizeof(short int) << " bytes" << std::endl;
    std::cout <<"long int: " << sizeof(long int) << " bytes" << std::endl;
    int n = 4, m = 5;
    std::cout <<"float: " << sizeof(float) << " bytes" << std::endl;
    int a[2] = {2, 4};
    std::cout <<"double: " << sizeof(double) << " bytes" << std::endl;
    std::cout <<"char: " << sizeof(char) << " bytes" << std::endl;
    return 0;
}

