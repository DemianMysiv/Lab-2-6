#include "Developer.h"
#include <iostream>
#include <string>

// Реалізація конструктора
Developer::Developer(std::string fullName, int idcardnumber, double salaryvalue, 
                     std::string position, std::string language, std::string github)
    : Employee(fullName, idcardnumber, salaryvalue, position), 
      programmingLanguage(language), githubProfile(github) 
{
    std::cout << "Developer створений!" << std::endl;
}

Developer::~Developer() {
    std::cout << "Developer деструктор!" << std::endl;
}

void Developer::writeCode() const {
    std::cout << "Writing code, using " << programmingLanguage << std::endl;
}

void Developer::debugCode() const {
    std::cout << "Developer debuged code." << std::endl;
}

void Developer::sendCommit() const {
    std::cout << "Sending commit, using Git: " << githubProfile << std::endl;
}

double Developer::calculateAnnualBonus() const {
    std::cout << "Розрахунок бонусу розробника." << getSalary() * 0.08 + 300.0 << std::endl;
    return getSalary() * 0.08 + 300.0;
}