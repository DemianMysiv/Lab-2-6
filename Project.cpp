#include "Project.h"

using namespace std;

Project::Project(string nazva, double koshty, int duration, bool status) 
    : title{ nazva }, budget{ koshty }, durationweeks{ duration }, isActive{ status } {
    cout << "Викликався конструктор за замовчуванням" << endl;
}

Project::Project(string zagolovok, double moneycount) 
    : title{ zagolovok }, budget{ moneycount }, durationweeks{ 5 }, isActive{ true } {}

Project::Project(const Project& other) 
    : title(other.title), budget(other.budget), 
      durationweeks(other.durationweeks), isActive(other.isActive) {
    cout << "Викликано конструктор КOПІЮВАННЯ для Project: " << title << endl;
}

Project::~Project() {
    cout << "Спрацював деструктор класу Project" << endl;
}

void Project::changeFinanciaton(double change) {
    budget += change;
}

void Project::profit() {
    cout << "Проєкт " << title << " успішно приносить прибуток компанії." << endl;
}

void Project::getStatusOfProject() {
    cout << "Статус проєкту " << title << " | Бюджет: " << budget << " | Тижнів: " << durationweeks << endl;
}

void Project::assignManager(Employee manager) {
    cout << "\n*** Призначення на проєкт: " << title << " ***" << endl;
    cout << "Керівник проєкту:" << endl;
    manager.showProfile(); // Клас Project викликає метод класу Employee!
    cout << "**************************************\n" << endl;
}