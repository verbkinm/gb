TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lprotobuf

SOURCES += \
        gb7.pb.cc \
        main.cpp \
        studentsgroup.cpp

HEADERS += \
    gb7.pb.h \
    studentsgroup.h

