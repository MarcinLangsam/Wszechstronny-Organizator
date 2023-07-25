QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../../../../Program Files/MySQL/Connector C++ 8.0/lib64'
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../../../../Program Files/MySQL/Connector C++ 8.0/lib64'
else:unix: LIBS += -L$$PWD/'../../../../Program Files/MySQL/MySQL Server 8.0/lib/' -llibmysql

INCLUDEPATH += $$PWD/'../../../../Program Files/MySQL/Connector C++ 8.0/include'
DEPENDPATH += $$PWD/'../../../../Program Files/MySQL/Connector C++ 8.0/include'
