TEMPLATE = app
TARGET = Teste_Vivo

QT = core gui
QT += widgets
QT += network
QT += xml

SOURCES += \
    window.cpp \
    main.cpp \
    xmldown.cpp \
    smoothstreaming.cpp

HEADERS += \
    window.h \
    xmldown.h \
    smoothstreaming.h
