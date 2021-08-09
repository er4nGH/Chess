QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bishop.cpp \
    blackwins.cpp \
    board.cpp \
    board2.cpp \
    bpawn.cpp \
    cell.cpp \
    chessman.cpp \
    king.cpp \
    knight.cpp \
    main.cpp \
    mainwindow.cpp \
    queen.cpp \
    rock.cpp \
    whitewins.cpp \
    wpawn.cpp

HEADERS += \
    bishop.h \
    blackwins.h \
    board.h \
    board2.h \
    bpawn.h \
    cell.h \
    chessman.h \
    king.h \
    knight.h \
    mainwindow.h \
    queen.h \
    rock.h \
    whitewins.h \
    wpawn.h

FORMS += \
    blackwins.ui \
    board.ui \
    board2.ui \
    mainwindow.ui \
    whitewins.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Pics.qrc
