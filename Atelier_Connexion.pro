#QT       += core gui sql
QT       += core gui sql network multimedia multimediawidgets charts printsupport widgets axcontainer
QT+= sql
 QT += charts
    QT += printsupport
QT += serialport
#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#CONFIG += c++11
QT       += core gui sql
QT+=sql
CONFIG += c++11
CONFIG += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app
TEMPLATE = app

QT +=charts
QT += printsupport

QT       += core gui sql printsupport
QT += multimedia

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    camera.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    piechart.cpp \
    salle.cpp \
arduino.cpp
HEADERS += \
    camera.h \
        mainwindow.h \
    connection.h \
    salle.h\
arduino.h

FORMS += \
        camera.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
