#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {

    /* Реализуйте этот конструктор */
	String(size_t n, char c){
        this -> size = n;
        char *temp = new char[size+1];
        for (size_t i = 0; i < n; i++)
        {
            temp[i] = c;
        }
        temp[size] = '\0';
        this -> str = temp;
                
    }

    /* и деструктор */
	~String(){
        delete [] str;
    }


	size_t size;
	char *str;
};


int main()
{
    String s(4, 'u');
    return 0;
}
