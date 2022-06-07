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
        ../app/text/*.h 

SOURCES += main.cpp \
  ../app/text/*.c \
  ../app/functions/* 

INCLUDEPATH += ../app \
  ../app/text

DISTFILES += input.txt
