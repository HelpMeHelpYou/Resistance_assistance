#-------------------------------------------------
#
# Project created by QtCreator 2013-08-29T17:33:25
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = resistance_assistant
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamers_model.cpp \
    actoradd.cpp \
    game.cpp \
    game_state.cpp \
    game_table_delegate.cpp \
    choose_leader.cpp \
    nominate.cpp \
    approve.cpp \
    execute.cpp \
    resistheaderview.cpp

HEADERS  += mainwindow.h \
    gamers_model.h \
    actoradd.h \
    game.h \
    game_state.h \
    game_table_delegate.h \
    choose_leader.h \
    nominate.h \
    approve.h \
    execute.h \
    resistheaderview.h \
    config.h

FORMS    += mainwindow.ui \
    actoradd.ui \
    game.ui \
    choose_leader.ui \
    nominate.ui \
    approve.ui \
    execute.ui

RESOURCES += \
    resource_file.qrc
