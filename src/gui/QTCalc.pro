# -------------------------------------------------
# Project created by QtCreator 2010-01-19T12:03:39
# -------------------------------------------------
TARGET = QTCalc
TEMPLATE = app
SOURCES += main.cpp \
    calculator.cpp
#    ../client/client.cpp \
#    ../validator/parser.cpp
HEADERS += calculator.h
FORMS += calculator.ui

INCLUDEPATH = ../client \
        ../validator
        