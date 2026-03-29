#pragma once
#include "CompanyAsset.h"
#include <string>

class Vehicle : public CompanyAsset {
private:
    std::string licensePlate;
    int mileage;

public:
    // Конструктор
    Vehicle(std::string id, double cost, int year, std::string plate, int startMileage);
    ~Vehicle();

    // Специфічні методи автомобіля
    void addMileage(int km);
    bool needsMaintenance() const;
    void displayVehicleInfo() const;

    virtual double  calculateMaintenanceCosts() const;
};