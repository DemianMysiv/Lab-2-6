#pragma once
#include <string>

class CompanyAsset {
private:
    std::string assetID;
    double purchaseCost;
    int purchaseYear;

public:
    // Конструктор
    CompanyAsset(std::string id, double cost, int year);
    ~CompanyAsset();

    // Геттери для доступу до приватних полів
    std::string getAssetID() const;
    double getPurchaseCost() const;
    int getPurchaseYear() const;

    // Метод для розрахунку знецінення
    double calculateDepreciation(int currentYear) const;
};