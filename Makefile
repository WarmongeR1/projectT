#############################################################################
# Makefile for building: build/bin/projectT
# Generated by qmake (2.01a) (Qt 4.7.0) on: ?? ???. 22 21:43:50 2012
# Project:  projectT.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile projectT.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_WEBKIT_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -march=i486 -mtune=i686 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -march=i486 -mtune=i686 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/lib/qt/mkspecs/linux-g++ -I. -I/usr/lib/qt/include/QtCore -I/usr/lib/qt/include/QtNetwork -I/usr/lib/qt/include/QtGui -I/usr/lib/qt/include/QtWebKit -I/usr/lib/qt/include -Isrc -Isrc/main -Isrc/dialogs/about -Isrc/highlighter -Isrc/htmleditor -Isrc/common -Isrc/defines -Ibuild/moc -Ibuild/ui
LINK          = g++
LFLAGS        = -Wl,-O1 -Wl,-rpath,/usr/lib/qt/lib
LIBS          = $(SUBLIBS)  -L/usr/lib/qt/lib -lQtWebKit -lQtGui -L/usr/lib/qt/lib -L/usr/X11R6/lib -lQtNetwork -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = build/obj/

####### Files

SOURCES       = src/htmleditor/htmleditor.cpp \
		src/main/main.cpp \
		src/highlighter/highlighter.cpp \
		src/dialogs/about/about.cpp \
		src/common/common.cpp build/moc/moc_htmleditor.cpp \
		build/moc/moc_highlighter.cpp \
		build/moc/moc_about.cpp \
		build/rc/qrc_resources.cpp
OBJECTS       = build/obj/htmleditor.o \
		build/obj/main.o \
		build/obj/highlighter.o \
		build/obj/about.o \
		build/obj/common.o \
		build/obj/moc_htmleditor.o \
		build/obj/moc_highlighter.o \
		build/obj/moc_about.o \
		build/obj/qrc_resources.o
DIST          = /usr/lib/qt/mkspecs/common/g++.conf \
		/usr/lib/qt/mkspecs/common/unix.conf \
		/usr/lib/qt/mkspecs/common/linux.conf \
		/usr/lib/qt/mkspecs/qconfig.pri \
		/usr/lib/qt/mkspecs/modules/qt_phonon.pri \
		/usr/lib/qt/mkspecs/modules/qt_webkit_version.pri \
		/usr/lib/qt/mkspecs/features/qt_functions.prf \
		/usr/lib/qt/mkspecs/features/qt_config.prf \
		/usr/lib/qt/mkspecs/features/exclusive_builds.prf \
		/usr/lib/qt/mkspecs/features/default_pre.prf \
		/usr/lib/qt/mkspecs/features/release.prf \
		/usr/lib/qt/mkspecs/features/default_post.prf \
		/usr/lib/qt/mkspecs/features/warn_on.prf \
		/usr/lib/qt/mkspecs/features/qt.prf \
		/usr/lib/qt/mkspecs/features/unix/thread.prf \
		/usr/lib/qt/mkspecs/features/moc.prf \
		/usr/lib/qt/mkspecs/features/resources.prf \
		/usr/lib/qt/mkspecs/features/uic.prf \
		/usr/lib/qt/mkspecs/features/yacc.prf \
		/usr/lib/qt/mkspecs/features/lex.prf \
		projectT.pro
QMAKE_TARGET  = projectT
DESTDIR       = build/bin/
TARGET        = build/bin/projectT

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): build/ui/ui_htmleditor.h build/ui/ui_inserthtmldialog.h build/ui/ui_about.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) build/bin/ || $(MKDIR) build/bin/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: projectT.pro  /usr/lib/qt/mkspecs/linux-g++/qmake.conf /usr/lib/qt/mkspecs/common/g++.conf \
		/usr/lib/qt/mkspecs/common/unix.conf \
		/usr/lib/qt/mkspecs/common/linux.conf \
		/usr/lib/qt/mkspecs/qconfig.pri \
		/usr/lib/qt/mkspecs/modules/qt_phonon.pri \
		/usr/lib/qt/mkspecs/modules/qt_webkit_version.pri \
		/usr/lib/qt/mkspecs/features/qt_functions.prf \
		/usr/lib/qt/mkspecs/features/qt_config.prf \
		/usr/lib/qt/mkspecs/features/exclusive_builds.prf \
		/usr/lib/qt/mkspecs/features/default_pre.prf \
		/usr/lib/qt/mkspecs/features/release.prf \
		/usr/lib/qt/mkspecs/features/default_post.prf \
		/usr/lib/qt/mkspecs/features/warn_on.prf \
		/usr/lib/qt/mkspecs/features/qt.prf \
		/usr/lib/qt/mkspecs/features/unix/thread.prf \
		/usr/lib/qt/mkspecs/features/moc.prf \
		/usr/lib/qt/mkspecs/features/resources.prf \
		/usr/lib/qt/mkspecs/features/uic.prf \
		/usr/lib/qt/mkspecs/features/yacc.prf \
		/usr/lib/qt/mkspecs/features/lex.prf \
		/usr/lib/qt/lib/libQtWebKit.prl \
		/usr/lib/qt/lib/libQtGui.prl \
		/usr/lib/qt/lib/libQtCore.prl \
		/usr/lib/qt/lib/libQtNetwork.prl
	$(QMAKE) -o Makefile projectT.pro
/usr/lib/qt/mkspecs/common/g++.conf:
/usr/lib/qt/mkspecs/common/unix.conf:
/usr/lib/qt/mkspecs/common/linux.conf:
/usr/lib/qt/mkspecs/qconfig.pri:
/usr/lib/qt/mkspecs/modules/qt_phonon.pri:
/usr/lib/qt/mkspecs/modules/qt_webkit_version.pri:
/usr/lib/qt/mkspecs/features/qt_functions.prf:
/usr/lib/qt/mkspecs/features/qt_config.prf:
/usr/lib/qt/mkspecs/features/exclusive_builds.prf:
/usr/lib/qt/mkspecs/features/default_pre.prf:
/usr/lib/qt/mkspecs/features/release.prf:
/usr/lib/qt/mkspecs/features/default_post.prf:
/usr/lib/qt/mkspecs/features/warn_on.prf:
/usr/lib/qt/mkspecs/features/qt.prf:
/usr/lib/qt/mkspecs/features/unix/thread.prf:
/usr/lib/qt/mkspecs/features/moc.prf:
/usr/lib/qt/mkspecs/features/resources.prf:
/usr/lib/qt/mkspecs/features/uic.prf:
/usr/lib/qt/mkspecs/features/yacc.prf:
/usr/lib/qt/mkspecs/features/lex.prf:
/usr/lib/qt/lib/libQtWebKit.prl:
/usr/lib/qt/lib/libQtGui.prl:
/usr/lib/qt/lib/libQtCore.prl:
/usr/lib/qt/lib/libQtNetwork.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile projectT.pro

dist: 
	@$(CHK_DIR_EXISTS) build/obj/projectT1.0.0 || $(MKDIR) build/obj/projectT1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/obj/projectT1.0.0/ && $(COPY_FILE) --parents src/htmleditor/htmleditor.h src/highlighter/highlighter.h src/dialogs/about/about.h src/common/common.h src/defines/defines.h build/obj/projectT1.0.0/ && $(COPY_FILE) --parents resources/resources.qrc build/obj/projectT1.0.0/ && $(COPY_FILE) --parents src/htmleditor/htmleditor.cpp src/main/main.cpp src/highlighter/highlighter.cpp src/dialogs/about/about.cpp src/common/common.cpp build/obj/projectT1.0.0/ && $(COPY_FILE) --parents src/htmleditor/htmleditor.ui src/dialogs/inserthtmldialog.ui src/dialogs/about/about.ui build/obj/projectT1.0.0/ && (cd `dirname build/obj/projectT1.0.0` && $(TAR) projectT1.0.0.tar projectT1.0.0 && $(COMPRESS) projectT1.0.0.tar) && $(MOVE) `dirname build/obj/projectT1.0.0`/projectT1.0.0.tar.gz . && $(DEL_FILE) -r build/obj/projectT1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: build/moc/moc_htmleditor.cpp build/moc/moc_highlighter.cpp build/moc/moc_about.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) build/moc/moc_htmleditor.cpp build/moc/moc_highlighter.cpp build/moc/moc_about.cpp
build/moc/moc_htmleditor.cpp: src/highlighter/highlighter.h \
		src/htmleditor/htmleditor.h
	/usr/lib/qt/bin/moc $(DEFINES) $(INCPATH) src/htmleditor/htmleditor.h -o build/moc/moc_htmleditor.cpp

build/moc/moc_highlighter.cpp: src/highlighter/highlighter.h
	/usr/lib/qt/bin/moc $(DEFINES) $(INCPATH) src/highlighter/highlighter.h -o build/moc/moc_highlighter.cpp

build/moc/moc_about.cpp: src/dialogs/about/about.h
	/usr/lib/qt/bin/moc $(DEFINES) $(INCPATH) src/dialogs/about/about.h -o build/moc/moc_about.cpp

compiler_rcc_make_all: build/rc/qrc_resources.cpp
compiler_rcc_clean:
	-$(DEL_FILE) build/rc/qrc_resources.cpp
build/rc/qrc_resources.cpp: resources/resources.qrc \
		resources/logo/qtlogo.png \
		resources/images/format-text-underline.png \
		resources/images/document-new.png \
		resources/images/edit-redo.png \
		resources/images/numbered-list.png \
		resources/images/list-remove.png \
		resources/images/insert-html.png \
		resources/images/edit-copy.png \
		resources/images/format-text-bold.png \
		resources/images/edit-undo.png \
		resources/images/format-justify-right.png \
		resources/images/format-justify-center.png \
		resources/images/format-justify-fill.png \
		resources/images/document-open.png \
		resources/images/text-html.png \
		resources/images/edit-paste.png \
		resources/images/format-indent-less.png \
		resources/images/bulleted-list.png \
		resources/images/list-add.png \
		resources/images/image-x-generic.png \
		resources/images/edit-select-all.png \
		resources/images/edit-cut.png \
		resources/images/format-indent-more.png \
		resources/images/document-save.png \
		resources/images/format-text-strikethrough.png \
		resources/images/format-justify-left.png \
		resources/images/format-text-italic.png \
		resources/files/example.html
	/usr/lib/qt/bin/rcc -name resources resources/resources.qrc -o build/rc/qrc_resources.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: build/ui/ui_htmleditor.h build/ui/ui_inserthtmldialog.h build/ui/ui_about.h
compiler_uic_clean:
	-$(DEL_FILE) build/ui/ui_htmleditor.h build/ui/ui_inserthtmldialog.h build/ui/ui_about.h
build/ui/ui_htmleditor.h: src/htmleditor/htmleditor.ui
	/usr/lib/qt/bin/uic src/htmleditor/htmleditor.ui -o build/ui/ui_htmleditor.h

build/ui/ui_inserthtmldialog.h: src/dialogs/inserthtmldialog.ui
	/usr/lib/qt/bin/uic src/dialogs/inserthtmldialog.ui -o build/ui/ui_inserthtmldialog.h

build/ui/ui_about.h: src/dialogs/about/about.ui
	/usr/lib/qt/bin/uic src/dialogs/about/about.ui -o build/ui/ui_about.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

build/obj/htmleditor.o: src/htmleditor/htmleditor.cpp src/htmleditor/htmleditor.h \
		src/highlighter/highlighter.h \
		src/defines/defines.h \
		src/dialogs/about/about.h \
		build/ui/ui_htmleditor.h \
		build/ui/ui_inserthtmldialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/htmleditor.o src/htmleditor/htmleditor.cpp

build/obj/main.o: src/main/main.cpp src/htmleditor/htmleditor.h \
		src/highlighter/highlighter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/main.o src/main/main.cpp

build/obj/highlighter.o: src/highlighter/highlighter.cpp src/highlighter/highlighter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/highlighter.o src/highlighter/highlighter.cpp

build/obj/about.o: src/dialogs/about/about.cpp src/dialogs/about/about.h \
		build/ui/ui_about.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/about.o src/dialogs/about/about.cpp

build/obj/common.o: src/common/common.cpp src/common/common.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/common.o src/common/common.cpp

build/obj/moc_htmleditor.o: build/moc/moc_htmleditor.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/moc_htmleditor.o build/moc/moc_htmleditor.cpp

build/obj/moc_highlighter.o: build/moc/moc_highlighter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/moc_highlighter.o build/moc/moc_highlighter.cpp

build/obj/moc_about.o: build/moc/moc_about.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/moc_about.o build/moc/moc_about.cpp

build/obj/qrc_resources.o: build/rc/qrc_resources.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/qrc_resources.o build/rc/qrc_resources.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

