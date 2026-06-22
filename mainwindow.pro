QT += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += main.cpp mainwindow.cpp serialarduino.cpp
HEADERS += mainwindow.h serialarduino.h
FORMS   += mainwindow.ui


