#include "developer.h"

Developer::Developer() {
    programmingLanguage = "";
}

std::string Developer::getProgrammingLanguage() {
    return programmingLanguage;
}

void Developer::setProgrammingLanguage(std::string newLanguage) {
    programmingLanguage = newLanguage;
}
