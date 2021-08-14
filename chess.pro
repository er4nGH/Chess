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

INCLUDEPATH += \
        ./include
		
SOURCES += \
    source/bishop.cpp \
    source/blackwins.cpp \
    source/board.cpp \
    source/board2.cpp \
    source/bpawn.cpp \
    source/cell.cpp \
    source/chessman.cpp \
    source/king.cpp \
    source/knight.cpp \
    source/main.cpp \
    source/mainwindow.cpp \
    source/queen.cpp \
    source/rock.cpp \
    source/whitewins.cpp \
    source/wpawn.cpp

HEADERS += \
    include/bishop.h \
    include/blackwins.h \
    include/board.h \
    include/board2.h \
    include/bpawn.h \
    include/cell.h \
    include/chessman.h \
    include/king.h \
    include/knight.h \
    include/mainwindow.h \
    include/queen.h \
    include/rock.h \
    include/whitewins.h \
    include/wpawn.h

FORMS += \
    ui/blackwins.ui \
    ui/board.ui \
    ui/board2.ui \
    ui/mainwindow.ui \
    ui/whitewins.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Pics.qrc
