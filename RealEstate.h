#pragma once
#include "CompanyAsset.h"
#include <string>

class RealEstate : public CompanyAsset {
private:
    std::string address;
    double squareMeters;

public:
    // Базовий конструктор
    RealEstate(std::string id, double cost, int year, std::string addressLoc, double sqMeters);
    
    RealEstate(const RealEstate& other);                  
    RealEstate(RealEstate&& other) noexcept;              
    RealEstate& operator=(const RealEstate& rhs);         
    
    ~RealEstate();

    // Специфічні методи нерухомості
    double calculateUtilityCost() const;
    void renovate() const;
    void displayEstateInfo() const;

    virtual double  calculateMaintenanceCosts() const override;

};