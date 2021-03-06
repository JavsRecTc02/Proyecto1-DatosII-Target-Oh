QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gamedisplay.cpp \
    gameimages.cpp \
    gameresults.cpp \
    gametargets.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    playeradvantages.cpp \
    restartgame.cpp

HEADERS += \
    gamedisplay.h \
    gameimages.h \
    gameresults.h \
    gametargets.h \
    mainwindow.h \
    player.h \
    playeradvantages.h \
    restartgame.h

FORMS += \
    gamedisplay.ui \
    mainwindow.ui

RC_ICONS = icon1.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
