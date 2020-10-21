TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        square.cpp

DISTFILES += \
    square.adt.txt \
    square.uml.png

HEADERS += \
    square.h
