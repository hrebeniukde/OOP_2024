TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        product.cpp

HEADERS += \
    clothingproduct.h \
    electronicproduct.h \
    foodproduct.h \
    inventory.h \
    product.h
