TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -static

SOURCES += main.cpp \
    map.cpp \
    game.cpp \
    display.cpp \
    gameplay.cpp \
    input.cpp

HEADERS += \
    map.h \
    game.h \
    display.h \
    gameplay.h \
    input.h
