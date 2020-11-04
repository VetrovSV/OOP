TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        complex.cpp \
        main.cpp \
        square.cpp

DISTFILES += \
    square.adt.txt \
    square.uml.png

HEADERS += \
    complex.h \
    square.h
