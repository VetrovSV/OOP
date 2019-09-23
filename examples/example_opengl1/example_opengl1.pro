TEMPLATE = app
CONFIG +=  c++11

# так не надо:
# CONFIG += console
# иначе будет создано консольное окно, в дополние к окну glut

CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp


LIBS += -lGL -lGLU -lglut
