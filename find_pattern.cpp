#include <iostream>
#include <iomanip>


unsigned strlen(const char * str) {
    int i = 0;
    for (; str[i] != '\0'; i++) {    }
    return i;
}

bool check_letter(const char *letter1, const char *letter2){
    if (*letter1 == *letter2){
        return true;
    }
    else {
        return false;
    }
}

int strstr(const char *text, const char *pattern)
{   
    int i = 0;
    int k_matched = 0;
    unsigned l1 = strlen(text);
    unsigned l2 = strlen(pattern);
    if (l1 < l2){
        return -1;
    }
    else if(l2 == 0){
        return 0;
    }
    else {
        for (; i < l1; i++){
            if (text[i] == pattern[0]){
                k_matched++;
                for (; k_matched < l2; k_matched++){
                    if (text[i+k_matched] != pattern[k_matched]){
                        k_matched = 0;
                        break;
                    }
                }
                if (k_matched !=0){
                    return i;
                }
            }
        }
        return -1;
    }
}


// int main(){
//     const char text[] = "a";
//     const char pat[] = "a";
//     std::cout << strstr(text, pat);
//     return 0;
// }


struct test{
    int ret_value;
    const char *text;
    const char *pattern;
};
test tests[] = {
        {0, "", ""}, //0
        {0, "a", ""}, //1
        {0, "a", "a"}, //2
        {-1, "a", "b"}, //3
        {0, "aa", ""}, //4
        {0, "aa", "a"}, //5
        {0, "ab", "a"}, //6
        {1, "ba", "a"}, //7
        {-1, "bb", "a"}, //8
        {0, "aaa", ""}, //9
        {0, "aaa", "a"}, //10
        {1, "abc", "b"}, //11
        {2, "abc", "c"}, //12
        {-1, "abc", "d"}, //13
        {-1, "a", "aa"}, //14
        {-1, "a", "ba"}, //15
        {-1, "a", "ab"}, //16
        {-1, "a", "bb"}, //17
        {-1, "a", "aaa"}, //18
        {-1, "aa", "aaa"}, //19
        {0, "aaa", "aaa"}, //20
        {0, "aaab", "aaa"}, //21
        {1, "baaa", "aaa"}, //22
        {1, "baaaa", "aaa"}, //23
        {1, "baaab", "aaa"}, //24
        {-1, "abd", "abc"}, //25
        {2, "ababc", "abc"}, //26
        {3, "abdabc", "abc"}, //27
        {-1, "", "a"}, //28
        {2, "asasaf", "asaf"}, //29
        {2, "ababac", "abac"} //30
};
int main(){
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
        int ret = strstr(tests[i].text, tests[i].pattern);
        (tests[i].ret_value == ret) ? std::cout << "OK" : std::cout << "Failed";
        std::cout << " : " << i << " (" << tests[i].ret_value << " : " << ret << ")" << std::endl;
        return 0;
    }
}

