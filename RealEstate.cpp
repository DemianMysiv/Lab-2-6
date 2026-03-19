#include "RealEstate.h"
#include <iostream>

// Передаємо дані "вгору" до батька
RealEstate::RealEstate(std::string id, double cost, int year, std::string addressLoc, double sqMeters)
    : CompanyAsset(id, cost, year), address(addressLoc), squareMeters(sqMeters) {}

// Розрахунок комунальних послуг (наприклад, $50 за квадратний метр)
double RealEstate::calculateUtilityCost() const {
    return squareMeters * 50.0;
}

// Симуляція ремонту
void RealEstate::renovate() const {
    std::cout << "Приміщення за адресою '" << address << "' (ID: " << getAssetID() 
              << ") було успішно відремонтовано.\n";
}

// Вивід інформації
void RealEstate::displayEstateInfo() const {
    std::cout << "--- Нерухомість [ID: " << getAssetID() << "] ---\n"
              << "Адреса: " << address << " | Площа: " << squareMeters << " кв.м\n"
              << "Вартість при покупці: $" << getPurchaseCost() << " | Рік: " << getPurchaseYear() << "\n";
}