TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        department.cpp \
        developer.cpp \
        employee.cpp \
        jobposition.cpp \
        main.cpp

HEADERS += \
    department.h \
    developer.h \
    employee.h \
    jobposition.h
