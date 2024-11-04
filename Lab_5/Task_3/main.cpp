#include "customstring.h"

#include <iostream>

int main()
{
    CustomString str1("Hello, ");
    CustomString str2("World!");

    CustomString str3 = str1 + str2;
    std::cout << "Concatenated string: " << str3 << std::endl;

    CustomString str4("Hello, World!");
    std::cout << "str3 == str4: " << (str3 == str4 ? "True" : "False") << std::endl;
    std::cout << "str1 != str2: " << (str1 != str2 ? "True" : "False") << std::endl;

    std::cout << "Character at index 7 in str3: " << str3[7] << std::endl;

    CustomString str5;
    str5 = str1;
    std::cout << "Assigned string: " << str5 << std::endl;

    return 0;
}
