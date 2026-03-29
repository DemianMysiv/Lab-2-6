#include "RealEstate.h"
#include <iostream>

RealEstate::RealEstate(std::string id, double cost, int year, std::string addressLoc, double sqMeters)
    : CompanyAsset(id, cost, year), address(addressLoc), squareMeters(sqMeters) {
        std::cout << "RealEstate Конструктор" << std::endl;
}

RealEstate::RealEstate(const RealEstate& other) 
    : CompanyAsset(other), 
      address(other.address), 
      squareMeters(other.squareMeters) 
{
    std::cout << "Викликано RealEstate Copy Constructor\n";
}

RealEstate::RealEstate(RealEstate&& other) noexcept
    : CompanyAsset(std::move(other)), 
      address(std::move(other.address)), 
      squareMeters(std::move(other.squareMeters)) 
{
    other.squareMeters = 0;
    std::cout << "Викликано RealEstate Move Constructor\n";
}

RealEstate& RealEstate::operator=(const RealEstate& rhs) {
    std::cout << "Викликано RealEstate Operator=\n";
    
    if (this != &rhs) {
        CompanyAsset::operator=(rhs); 
        
        address = rhs.address;
        squareMeters = rhs.squareMeters;
    }
    return *this;
}

RealEstate::~RealEstate() {
    std::cout << "Викликано деструктор для RealEstate" << std::endl;
}

double RealEstate::calculateUtilityCost() const {
    return squareMeters * 50.0;
}

void RealEstate::renovate() const {
    std::cout << "Приміщення за адресою '" << address << "' (ID: " << getAssetID() 
              << ") було успішно відремонтовано.\n";
}

void RealEstate::displayEstateInfo() const {
    std::cout << "--- Нерухомість [ID: " << getAssetID() << "] ---\n"
              << "Адреса: " << address << " | Площа: " << squareMeters << " кв.м\n"
              << "Вартість при покупці: $" << getPurchaseCost() << " | Рік: " << getPurchaseYear() << "\n";
}

double RealEstate::calculateMaintenanceCosts() const{
    // Припустимо, що витрати на обслуговування залежать від площі

    std::cout << "Розрахунок витрат на обслуговування для нерухомості з площею: " << squareMeters << " кв.м" << std::endl;
    if (squareMeters < 50) {
        return 200.0; // Легке обслуговування
    } else if (squareMeters < 150) {
        return 500.0; // Середнє обслуговування
    } else {
        return 1000.0; // Повне обслуговування
    }
}
