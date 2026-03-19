#pragma once
#include "CompanyAsset.h"
#include <string>

class RealEstate : public CompanyAsset {
private:
    std::string address;
    double squareMeters;

public:
    // Конструктор
    RealEstate(std::string id, double cost, int year, std::string addressLoc, double sqMeters);

    // Специфічні методи нерухомості
    double calculateUtilityCost() const;
    void renovate() const;
    void displayEstateInfo() const;
};