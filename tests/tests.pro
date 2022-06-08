include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra
QMAKE_CFLAGS += -Wall -Wextra

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DEFINES += INPUTDIR=\\\"$$PWD/\\\"

HEADERS += tests.h \
        ../app/common.h \
        ../text/*.h 

SOURCES += main.cpp \
  ../text/*.c \
  ../functions/* 

INCLUDEPATH += ../app \
  ../text

DISTFILES += input.txt
