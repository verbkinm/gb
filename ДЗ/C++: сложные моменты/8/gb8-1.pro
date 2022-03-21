include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

SOURCES += \
        1/person.cpp \
        1/phonebook.cpp \
        1/phonenumber.cpp \
        main.cpp         tst_t1.cpp

DISTFILES += \
    1/PhoneBook.txt

HEADERS += \
    1/person.h \
    1/phonebook.h \
    1/phonenumber.h
