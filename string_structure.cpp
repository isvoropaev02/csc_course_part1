#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <iostream>


struct String {
    // оказалась не нужной
    // size_t strlen(const char * str) {
    //     size_t i = 0;
    //     for (; str[i] != '\0'; i++) {    }
    //     return i;
    // }
	String(const char *str = ""){
        this -> size = strlen(str);
        char *temp = new char[size+1];
        strcpy(temp, str);
        temp[size] = '\0';
        this -> str = temp;
    }

	size_t size;
	char *str;
};


int main()
{   
    char s_initial[20] = "reumdeuter";
     
    String s(s_initial);
    
    std::cout << s.size << std::endl;
    for (size_t i = 0; i < s.size; i++)
    {
        std::cout << s.str[i];
    }
    std::cout << std::endl;
    
    return 0;
}
