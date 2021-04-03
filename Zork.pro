TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

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

QT += widgets

FORMS += \
    mainwindow.ui
