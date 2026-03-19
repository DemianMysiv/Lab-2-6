#include "CompanyAsset.h"

// Ініціалізуємо приватні поля через список ініціалізації
CompanyAsset::CompanyAsset(std::string id, double cost, int year)
    : assetID(id), purchaseCost(cost), purchaseYear(year) {}

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