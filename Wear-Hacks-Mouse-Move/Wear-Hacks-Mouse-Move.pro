TEMPLATE = app

QT += qml quick widgets serialport

SOURCES += main.cpp \
    serialreader.cpp \
    mousemove.cpp

RESOURCES +=

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

msvc: LIBS += -luser32

HEADERS += \
    serialreader.h \
    mousemove.h
