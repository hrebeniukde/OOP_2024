#include <iostream>

#include "warehouse.h"

using namespace std;

int main()
{
    system("chcp 65001 & cls");

    Warehouse warehouse;

    warehouse.addPart(Part("Гальмівні колодки", "Brembo", 1500.0, 20));
    warehouse.addPart(Part("Масляний фільтр", "Bosch", 300.0, 50));
    warehouse.addPart(Part("Свічки запалювання", "Denso", 200.0, 100));

    std::cout << "Список запчастин на складі:" << std::endl;
    warehouse.printParts();

    warehouse.removePartByName("Масляний фільтр");

    warehouse.updatePart("Свічки запалювання", 220.0, 90);

    std::cout << "\nОновлений список запчастин на складі:" << std::endl;
    warehouse.printParts();

    std::cout << "\nПошук запчастини 'Гальмівні колодки':" << std::endl;
    warehouse.findPartByName("Гальмівні колодки");

    warehouse.sortPartsByPrice();
    std::cout << "\nСписок запчастин після сортування за ціною (за зростанням):" << std::endl;
    warehouse.printParts();

    return 0;
}
