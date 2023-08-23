#include <iostream>


char *resize(const char *str, unsigned size, unsigned new_size)
{
	char * new_string = new char[new_size];

    for (int i = 0; (i < new_size) && (i < size); i++)
    {
        new_string[i] = str[i];
    }
    delete [] str;
    return new_string;
    
}


// testing part

int main(){
    char *str = new char[10];
    std::string s = "fffffffddd";
    int curr = 0;
    for (char el: s){
        str[curr] = el;
        curr++;
    }
    char *a = resize(str, 10, 8);
    for (int i = 0; i < 17; i++){
        std::cout << a[i];
    }
}
