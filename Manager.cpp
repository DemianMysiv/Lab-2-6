#include "Manager.h"
#include <iostream>
#include <string>

Manager::Manager(std::string Name, int id, double salary, int team, std::string dept, std::string position) 
    : Employee(Name, id, salary, position), teamSize(team), department(dept) {
    std::cout << "Викликано конструктор для Manager з 6 параметрами" << std::endl;
}

Manager::~Manager() {
    std::cout << "Викликано деструктор для Manager" << std::endl;
}

void Manager::addTeamMember() {
    teamSize++;
    std::cout << "Додано нового члена команди. Розмір команди: " << teamSize << std::endl;
}

void Manager::conductMeeting() const {
    std::cout << "Проведення зустрічі для відділу " << department << std::endl;
}

void Manager::showneededinfo()const{
    std::cout<< "Ось додаткова інформація про менеджера: " << std::endl;
    std::cout << "Менеджер: " << getSalary() << ", Розмір команди: " << teamSize << ", Відділ: " << department << std::endl;

    
}
