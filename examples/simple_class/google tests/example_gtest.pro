TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

# в том числе cc файлы google test'а
# за исключением gtest-internal-inl.h и gtest_main.cc
# без них - undefined reference

SOURCES += \
        ../seconds.cpp \
        gtest/src/gtest-all.cc \
        gtest/src/gtest-death-test.cc \
        gtest/src/gtest-filepath.cc \
        gtest/src/gtest-matchers.cc \
        gtest/src/gtest-port.cc \
        gtest/src/gtest-printers.cc \
        gtest/src/gtest-test-part.cc \
        gtest/src/gtest-typed-test.cc \
        gtest/src/gtest.cc \
        main.cpp

INCLUDEPATH += gtest/include
INCLUDEPATH += gtest

HEADERS += \
    ../seconds.h


# нужна google test'у
LIBS += -pthread
