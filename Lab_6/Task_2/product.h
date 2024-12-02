#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
protected:
    std::string name;
    double price;
    int quantity;

public:
    Product(const std::string& name_, double price_, int quantity_)
        : name(name_), price(price_), quantity(quantity_) {}

    std::string getName() const;
    double getPrice() const;
    int getQuantity() const;

    virtual void display() const;
};

#endif // PRODUCT_H
