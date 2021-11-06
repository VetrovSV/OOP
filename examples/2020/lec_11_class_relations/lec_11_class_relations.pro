TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        date.cpp \
        main.cpp \
        person.cpp \
        sertificate.cpp \
        university.cpp

HEADERS += \
    date.h \
    person.h \
    sertificate.h \
    university.h

DISTFILES += \
    uml.png
