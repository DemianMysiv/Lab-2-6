#include "Manager.h"
#include <iostream>
#include <string>

Manager::Manager(std::string id, double salary, int team, std::string dept) : Employee(id, salary), teamSize(team), department(dept) {
        std::cout << "Викликано конструктор для Manager з 4 параметрами" << std::endl;
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
