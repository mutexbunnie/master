#############################################################################
# Makefile for building: master
# Generated by qmake (2.01a) (Qt 4.8.2) on: Thu Aug 30 19:59:50 2012
# Project:  master.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile master.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
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

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainform.cpp \
		entity.cpp \
		activedialog.cpp moc_mainform.cpp \
		moc_entity.cpp \
		moc_activedialog.cpp \
		qrc_icons.cpp
OBJECTS       = main.o \
		mainform.o \
		entity.o \
		activedialog.o \
		moc_mainform.o \
		moc_entity.o \
		moc_activedialog.o \
		qrc_icons.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/declarative_debug.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		master.pro
QMAKE_TARGET  = master
DESTDIR       = 
TARGET        = master

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

$(TARGET): ui_mainform.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9]\+\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: master.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/declarative_debug.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile master.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/declarative_debug.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile master.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/master1.0.0 || $(MKDIR) .tmp/master1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/master1.0.0/ && $(COPY_FILE) --parents mainform.h entity.h activedialog.h .tmp/master1.0.0/ && $(COPY_FILE) --parents icons.qrc .tmp/master1.0.0/ && $(COPY_FILE) --parents main.cpp mainform.cpp entity.cpp activedialog.cpp .tmp/master1.0.0/ && $(COPY_FILE) --parents mainform.ui .tmp/master1.0.0/ && (cd `dirname .tmp/master1.0.0` && $(TAR) master1.0.0.tar master1.0.0 && $(COMPRESS) master1.0.0.tar) && $(MOVE) `dirname .tmp/master1.0.0`/master1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/master1.0.0


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

compiler_moc_header_make_all: moc_mainform.cpp moc_entity.cpp moc_activedialog.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainform.cpp moc_entity.cpp moc_activedialog.cpp
moc_mainform.cpp: activedialog.h \
		entity.h \
		mainform.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainform.h -o moc_mainform.cpp

moc_entity.cpp: entity.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) entity.h -o moc_entity.cpp

moc_activedialog.cpp: entity.h \
		activedialog.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) activedialog.h -o moc_activedialog.cpp

compiler_rcc_make_all: qrc_icons.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_icons.cpp
qrc_icons.cpp: icons.qrc
	/usr/bin/rcc -name icons icons.qrc -o qrc_icons.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainform.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainform.h
ui_mainform.h: mainform.ui
	/usr/bin/uic-qt4 mainform.ui -o ui_mainform.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainform.h \
		activedialog.h \
		entity.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainform.o: mainform.cpp mainform.h \
		activedialog.h \
		entity.h \
		ui_mainform.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainform.o mainform.cpp

entity.o: entity.cpp entity.h \
		activedialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o entity.o entity.cpp

activedialog.o: activedialog.cpp activedialog.h \
		entity.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o activedialog.o activedialog.cpp

moc_mainform.o: moc_mainform.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainform.o moc_mainform.cpp

moc_entity.o: moc_entity.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_entity.o moc_entity.cpp

moc_activedialog.o: moc_activedialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_activedialog.o moc_activedialog.cpp

qrc_icons.o: qrc_icons.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_icons.o qrc_icons.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

