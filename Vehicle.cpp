#include "Vehicle.h"
#include <iostream>

// Делегуємо базові дані конструктору CompanyAsset, свої поля ініціалізуємо самі
Vehicle::Vehicle(std::string id, double cost, int year, std::string plate, int startMileage)
    : CompanyAsset(id, cost, year), licensePlate(plate), mileage(startMileage) {
        std::cout << "Vehicle Конструктор" << std::endl;
    }

Vehicle::~Vehicle() {
    std::cout << "Викликано деструктор для Vehicle" << std::endl;
}  

// Додаємо пробіг
void Vehicle::addMileage(int km) {
    if (km > 0) {
        mileage += km;
    }
}

// Перевіряємо, чи потрібне ТО (наприклад, якщо пробіг більше 15 000 км)
bool Vehicle::needsMaintenance() const {
    return mileage >= 15000;
}

// Виводимо інформацію, використовуючи геттери базового класу
void Vehicle::displayVehicleInfo() const {
    std::cout << "--- Автомобіль [ID: " << getAssetID() << "] ---\n"
              << "Номерний знак: " << licensePlate << " | Пробіг: " << mileage << " км\n"
              << "Вартість при покупці: $" << getPurchaseCost() << " | Рік: " << getPurchaseYear() << "\n";
}



double Vehicle::calculateMaintenanceCosts() const {
    // Припустимо, що витрати на обслуговування залежать від пробігу
    std::cout << "Розрахунок витрат на обслуговування для автомобіля з пробігом: " << mileage << " км" << std::endl;
    if ( mileage < 5000) {
        return 100.0; // Легке ТО
    } else if (mileage < 15000) {
        return 300.0; // Середнє ТО
    } else {
        return 600.0; // Повне ТО
    }
}

