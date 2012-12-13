TEMPLATE  = app
QT       += network webkit


PROJECTNAME = projecT
DESTDIR     = build/bin
OBJECTS_DIR = build/obj
MOC_DIR     = build/moc
RCC_DIR     = build/rc
UI_DIR      = build/ui

INCLUDEPATH = \
    src \
    src/main \
    src/dialogs/about \
    src/highlighter \
    src/mainwindow \
    src/common \
    src/defines \
    src/panel/leftpanel \
    src/panel/rightpanel \
    src/debughelper

DEPENDPATH += \
    src \
    src/main \
    src/dialogs/about \
    src/dialogs/ \
    src/highlighter \
    src/mainwindow \
    src/common \
    src/defines \
    src/panel/leftpanel \
    src/panel/rightpanel \
    src/debughelper


HEADERS   += \
        mainwindow.h \
        highlighter.h \
        about.h \
        common.h \
        defines.h \
        rightpanel.h \
        leftpanel.h \
        debughelper.h

SOURCES   += \
        mainwindow.cpp \
        main.cpp \
        highlighter.cpp \
        about.cpp \
        common.cpp \
        rightpanel.cpp \
        leftpanel.cpp \
        debughelper.cpp

FORMS     += \
        mainwindow.ui \
        inserthtmldialog.ui \
        about.ui \
        rightpanel.ui \
        leftpanel.ui

RESOURCES += \
    resources/resources.qrc

TRANSLATIONS += \
    resources/lang/projectT_ru.ts
