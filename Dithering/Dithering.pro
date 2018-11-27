TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += \
        main.cpp \
    palette.cpp \
    ditherfactory.cpp \
    atkinsondither.cpp \
    floydsteinbergdither.cpp \
    sierradither.cpp \
    sierralitedither.cpp \
    tworowsierradither.cpp

HEADERS += \
    palette.h \
    idither.h \
    ditherfactory.h \
    floydsteinbergdither.h \
    atkinsondither.h \
    RgbColor.h \
    sierradither.h \
    tworowsierradither.h \
    sierralitedither.h \
    tworowsierradither.h \
    nulldither.h
