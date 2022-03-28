TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Bomb.cpp \
        Ground.cpp \
        House.cpp \
        LevelGUI.cpp \
        MyTools.cpp \
        Plane.cpp \
        SBomber.cpp \
        SBomberProject.cpp \
        Tank.cpp \
 \        #main.cpp
    logsingleton.cpp

HEADERS += \
    Bomb.h \
    DestroyableGroundObject.h \
    DynamicObject.h \
    GameObject.h \
    Ground.h \
    House.h \
    LevelGUI.h \
    MyTools.h \
    Plane.h \
    SBomber.h \
    Tank.h \
    logsingleton.h
