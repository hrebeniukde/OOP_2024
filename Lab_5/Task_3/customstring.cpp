#include "customstring.h"

#include <string.h>

CustomString::CustomString(const char *content) {
    contentSize = strlen(content) + 1;
    this->content = new char[contentSize];
    strncpy(this->content, content, contentSize - 1);
    this->content[contentSize - 1] = '\0';
}

CustomString::~CustomString() {
    delete[] content;
}

CustomString CustomString::operator+(const CustomString &other) const {
    int newSize = contentSize + other.contentSize - 1;
    char *newContent = new char[newSize];

    strncpy(newContent, content, contentSize - 1);
    strncpy(newContent + contentSize - 1, other.content, other.contentSize);

    CustomString result(newContent);
    delete[] newContent;
    return result;
}

bool CustomString::operator==(const CustomString &other) const {
    return strcmp(content, other.content) == 0;
}

bool CustomString::operator!=(const CustomString &other) const {
    return !(*this == other);
}

char &CustomString::operator[](int index) {
    if (index < 0 || index >= contentSize - 1) {
        throw "Index out of range";
    }

    return content[index];
}

std::ostream &operator<<(std::ostream &os, const CustomString &object) {
    os << object.content;
    return os;
}
