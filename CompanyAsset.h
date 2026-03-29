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
    virtual ~CompanyAsset();

    // Геттери для доступу до приватних полів
    std::string getAssetID() const;
    double getPurchaseCost() const;
    int getPurchaseYear() const;

    // Метод для розрахунку знецінення
    double calculateDepreciation(int currentYear) const;

        // Метод для розрахунку витрат на технічне обслуговування
    virtual double calculateMaintenanceCosts() const;

};