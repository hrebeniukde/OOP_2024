#include <iostream>

#include "inventory.h"
#include "product.h"
#include "foodproduct.h"
#include "electronicproduct.h"
#include "clothingproduct.h"

using namespace std;

int main()
{
    system("chcp 65001 & cls");

    Inventory<Product*> inventory;

    inventory.addProduct(new FoodProduct("Яблука", 30.0, 100, "01.12.2024"));
    inventory.addProduct(new ElectronicProduct("Телефон", 5000.0, 10, 24));
    inventory.addProduct(new ClothingProduct("Футболка", 250.0, 50, "M"));

    std::cout << "Список всіх товарів на складі:\n";
    inventory.displayAllProducts();

    double searchPrice = 250.0;
    std::cout << "\nТовари з ціною " << searchPrice << ":\n";
    inventory.findProductsByPrice(searchPrice);

    std::string removeName = "Телефон";
    std::cout << std::endl;
    inventory.removeProductByName(removeName);

    std::cout << "\nОновлений список товарів на складі:\n";
    inventory.displayAllProducts();

    return 0;
}
