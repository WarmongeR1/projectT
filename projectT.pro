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
    src/htmleditor \
    src/common \
    src/defines

DEPENDPATH += \
    src \
    src/main \
    src/dialogs/about \
    src/dialogs/ \
    src/highlighter \
    src/htmleditor \
    src/common \
    src/defines 


HEADERS   += \
	htmleditor.h \
	highlighter.h \
	about.h \
	common.h \
    defines.h

SOURCES   += \
	htmleditor.cpp \
	main.cpp \
	highlighter.cpp \
	about.cpp \
	common.cpp

FORMS     += \
	htmleditor.ui \
	inserthtmldialog.ui \
	about.ui

RESOURCES += \
    resources/resources.qrc

