#include "Developer.h"
#include <iostream>


void Developer::writeCode() const {
    std::cout << "Writing code, using " << programmingLanguage << std::endl;
}

void Developer::debugCode() const {
    std::cout << "Developer debuged code." << std::endl;
}

void Developer::sendCommit() const {
    std::cout << "Sending commit, using Git: " << githubProfile << std::endl;
}