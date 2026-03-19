#include "Manager.h"
#include <iostream>

void Manager::addTeamMember() {
    teamSize++;
    std::cout << "Додано нового члена команди. Розмір команди: " << teamSize << std::endl;
}

void Manager::conductMeeting() const {
    std::cout << "Проведення зустрічі для відділу " << department << std::endl;
}
