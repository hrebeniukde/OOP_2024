TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        instrument.cpp \
        main.cpp \
        manager.cpp \
        musicband.cpp \
        musician.cpp \
        vocalist.cpp

HEADERS += \
    instrument.h \
    manager.h \
    musicband.h \
    musician.h \
    vocalist.h
