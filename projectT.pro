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
    src/panel/rightpanel

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
    src/panel/rightpanel


HEADERS   += \
	mainwindow.h \
	highlighter.h \
	about.h \
	common.h \
    defines.h \
    src/panel/rightpanel/rightpanel.h \
    src/panel/leftpanel/leftpanel.h

SOURCES   += \
	mainwindow.cpp \
	main.cpp \
	highlighter.cpp \
	about.cpp \
	common.cpp \
    src/panel/rightpanel/rightpanel.cpp \
    src/panel/leftpanel/leftpanel.cpp

FORMS     += \
	mainwindow.ui \
	inserthtmldialog.ui \
	about.ui \
    src/panel/rightpanel/rightpanel.ui \
    src/panel/leftpanel/leftpanel.ui

RESOURCES += \
    resources/resources.qrc

TRANSLATIONS += \
    resources/lang/projectT_ru.ts
