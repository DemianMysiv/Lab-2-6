#pragma once

class IDisplayable {
public:
    virtual ~IDisplayable() = default; 

    virtual void display() const = 0; 

    virtual std::string toFileString() const = 0;
};