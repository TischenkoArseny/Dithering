TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += \
        main.cpp \
    rgb_color.cpp \
    palette.cpp \
    ditherfactory.cpp \
    floydsteinbergdither.cpp \
    atkinsondither.cpp

HEADERS += \
    rgb_color.h \
    palette.h \
    idither.h \
    ditherfactory.h \
    dithermethodid.h \
    floydsteinbergdither.h \
    atkinsondither.h
