#include "CompanyAsset.h"
#include <iostream>

// Ініціалізуємо приватні поля через список ініціалізації
CompanyAsset::CompanyAsset(std::string id, double cost, int year)
    : assetID(id), purchaseCost(cost), purchaseYear(year) {
    std::cout << "Викликано конструктор для CompanyAsset з ID: " << assetID << std::endl;
    }

CompanyAsset::~CompanyAsset() {
    std::cout << "Викликано деструктор для CompanyAsset" << std::endl;
}


// Реалізація геттерів
std::string CompanyAsset::getAssetID() const { 
    return assetID; 
}
double CompanyAsset::getPurchaseCost() const { 
    return purchaseCost; 
}
int CompanyAsset::getPurchaseYear() const { 
    return purchaseYear; 
}

// Логіка знецінення (актив втрачає 10% вартості щороку)
double CompanyAsset::calculateDepreciation(int currentYear) const {
    int yearsOld = currentYear - purchaseYear;
    if (yearsOld <= 0) return 0.0;
    
    double depreciation = purchaseCost * 0.10 * yearsOld;
    if (depreciation > purchaseCost) {
        return purchaseCost; // Актив не може знецінитися більше, ніж коштував
    }
    return depreciation;
}

double CompanyAsset::calculateMaintenanceCosts() const {
    // Припустимо, що щорічні витрати на обслуговування складають 5% від вартості при покупці
    std::cout << "Розрахунок приблизних витрат на обслуговування для активу." << std::endl;
    return purchaseCost * 0.05;
}