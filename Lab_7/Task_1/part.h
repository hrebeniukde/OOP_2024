#ifndef PART_H
#define PART_H

#include <string>

class Part {
private:
    std::string name;
    std::string manufacturer;
    double price;
    int quantity;

public:
    Part(const std::string& name, const std::string& manufacturer, double price, int quantity)
        : name(name), manufacturer(manufacturer), price(price), quantity(quantity) {}

    std::string getName() const;

    double getPrice() const;

    void setPrice(double newPrice);

    void setQuantity(int newQuantity);

    void print() const;

};

#endif // PART_H
