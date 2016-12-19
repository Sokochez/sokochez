TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = build
OBJECTS_DIR = build
MOC_DIR = build
RCC_DIR = build
UI_DIR = build

SOURCES += main.cpp \
    map.cpp \
    game.cpp \
    display.cpp \
    gameplay.cpp

HEADERS += \
    map.h \
    game.h \
    display.h \
    gameplay.h
