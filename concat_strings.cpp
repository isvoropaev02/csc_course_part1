#include <string>
#include <iostream>

unsigned strlen(const char * str) {
    int i = 0;
    for (; str[i] != '\0'; i++) {    }
    return i;
}

char strconcat(char *to, const char *from)
{
    int l1 = strlen(to);
    int l2 = strlen(from);
    for (int i = 0; i < l2 + 1; i++) {
        to[l1] = from[i];
        l1++;
    }
    return *to;
}

int main(){
    char a[100] = "dfred";
    char b[100] = "gtrur";
    strconcat(a, b);
    std::cout << a;
    std::cout << strlen(b);
    return 0;
}