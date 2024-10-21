TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    bankaccount.cpp \
    interestaccount.cpp \
    main.cpp \
    regularaccount.cpp

HEADERS += \
    bankaccount.h \
    interestaccount.h \
    regularaccount.h
