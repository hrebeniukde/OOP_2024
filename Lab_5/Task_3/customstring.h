#ifndef CUSTOMSTRING_H
#define CUSTOMSTRING_H

#include <iostream>

class CustomString
{
public:
    CustomString(const char *content = "");
    ~CustomString();

    CustomString operator+(const CustomString &other) const;
    bool operator==(const CustomString &other) const;
    bool operator!=(const CustomString &other) const;
    char &operator[](int index);

    friend std::ostream &operator<<(std::ostream &os, const CustomString &object);

private:
    char *content;
    int contentSize;

    void copyContent(const char *source);

};

#endif
