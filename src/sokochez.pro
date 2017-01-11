TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_MAC_SDK = macosx10.12
LIBS += -static

SOURCES += main.cpp \
    map.cpp \
    game.cpp \
    display.cpp \
    gameplay.cpp \
    input.cpp \
    editor.cpp

HEADERS += \
    map.h \
    game.h \
    display.h \
    gameplay.h \
    input.h \
    editor.h
