QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Character.cpp \
    Command.cpp \
    CommandWords.cpp \
    Door.cpp \
    NPC.cpp \
    Parser.cpp \
    Room.cpp \
    ZorkUL.cpp \
    enemy.cpp \
    item.cpp \
    itemlist.cpp \
    mainwindow.cpp \
    monsterlist.cpp

HEADERS += \
    Character.h \
    Command.h \
    CommandWords.h \
    Door.h \
    NPC.h \
    Parser.h \
    Room.h \
    ZorkUL.h \
    enemy.h \
    item.h \
    itemlist.h \
    mainwindow.h \
    monsterlist.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    Zork.pro \
    Zork.pro

DISTFILES += \
    Donkey.png \
    Zork.pro.user \
    buffdonkey.jpg \
    joe.png \
    shrek.jpg \
    untitled1.pro.user

RESOURCES += \
    Resources.qrc
