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
    src/defines

DEPENDPATH += \
    src \
    src/main \
    src/dialogs/about \
    src/dialogs/ \
    src/highlighter \
    src/mainwindow \
    src/common \
    src/defines


HEADERS   += \
	mainwindow.h \
	highlighter.h \
	about.h \
	common.h \
    defines.h

SOURCES   += \
	mainwindow.cpp \
	main.cpp \
	highlighter.cpp \
	about.cpp \
	common.cpp

FORMS     += \
	mainwindow.ui \
	inserthtmldialog.ui \
	about.ui

RESOURCES += \
    resources/resources.qrc

