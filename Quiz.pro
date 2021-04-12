QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    databaseconnection.cpp \
    datamanager.cpp \
    gamecontroller.cpp \
    gamedatawriter.cpp \
    gameinitializer.cpp \
    gamemanager.cpp \
    gamewindow.cpp \
    main.cpp \
    mainwindow.cpp \
    question.cpp

HEADERS += \
    databaseconnection.h \
    datamanager.h \
    gamecontroller.h \
    gamedatawriter.h \
    gameinitializer.h \
    gamemanager.h \
    gamewindow.h \
    mainwindow.h \
    question.h

FORMS += \
    gamewindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
