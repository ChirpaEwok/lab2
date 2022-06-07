TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += editor.c \
  functions/* \
  text/*.c

HEADERS += common.h \
  text/text.h \
  text/_text.h

QMAKE_CFLAGS += -Wall -Wextra #-Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
TARGET = editor
