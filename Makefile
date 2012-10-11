#############################################################################
# Makefile for building: master
# Generated by qmake (2.01a) (Qt 4.8.2) on: Tue Sep 25 00:58:56 2012
# Project:  master.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile master.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_SQL_LIB -DQT_XML_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtXml -I/usr/include/qt4/QtSql -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtSql -lQtXml -lQtGui -lQtCore -lpthread 
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
		activedialog.cpp \
		entitytype.cpp \
		entitytypebutton.cpp \
		fieldmap.cpp \
		projectstore.cpp \
		stringintturple.cpp \
		datasource.cpp \
		mysqldatasource.cpp moc_mainform.cpp \
		moc_entity.cpp \
		moc_activedialog.cpp \
		moc_entitytypebutton.cpp \
		qrc_icons.cpp
OBJECTS       = main.o \
		mainform.o \
		entity.o \
		activedialog.o \
		entitytype.o \
		entitytypebutton.o \
		fieldmap.o \
		projectstore.o \
		stringintturple.o \
		datasource.o \
		mysqldatasource.o \
		moc_mainform.o \
		moc_entity.o \
		moc_activedialog.o \
		moc_entitytypebutton.o \
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
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
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
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
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
		/usr/lib/x86_64-linux-gnu/libQtSql.prl \
		/usr/lib/x86_64-linux-gnu/libQtXml.prl \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile master.pro
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
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
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
/usr/lib/x86_64-linux-gnu/libQtSql.prl:
/usr/lib/x86_64-linux-gnu/libQtXml.prl:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile master.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/master1.0.0 || $(MKDIR) .tmp/master1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/master1.0.0/ && $(COPY_FILE) --parents mainform.h entity.h activedialog.h entitytype.h entitytypebutton.h fielddescription.h fieldmap.h projectstore.h stringintturple.h datasource.h mysqldatasource.h .tmp/master1.0.0/ && $(COPY_FILE) --parents icons.qrc .tmp/master1.0.0/ && $(COPY_FILE) --parents main.cpp mainform.cpp entity.cpp activedialog.cpp entitytype.cpp entitytypebutton.cpp fieldmap.cpp projectstore.cpp stringintturple.cpp datasource.cpp mysqldatasource.cpp .tmp/master1.0.0/ && $(COPY_FILE) --parents mainform.ui .tmp/master1.0.0/ && (cd `dirname .tmp/master1.0.0` && $(TAR) master1.0.0.tar master1.0.0 && $(COMPRESS) master1.0.0.tar) && $(MOVE) `dirname .tmp/master1.0.0`/master1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/master1.0.0


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

compiler_moc_header_make_all: moc_mainform.cpp moc_entity.cpp moc_activedialog.cpp moc_entitytypebutton.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainform.cpp moc_entity.cpp moc_activedialog.cpp moc_entitytypebutton.cpp
moc_mainform.cpp: activedialog.h \
		entity.h \
		entitytype.h \
		fieldmap.h \
		fielddescription.h \
		datasource.h \
		stringintturple.h \
		projectstore.h \
		entitytypebutton.h \
		mainform.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainform.h -o moc_mainform.cpp

moc_entity.cpp: entitytype.h \
		fieldmap.h \
		fielddescription.h \
		datasource.h \
		stringintturple.h \
		entity.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) entity.h -o moc_entity.cpp

moc_activedialog.cpp: entity.h \
		entitytype.h \
		fieldmap.h \
		fielddescription.h \
		datasource.h \
		stringintturple.h \
		activedialog.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) activedialog.h -o moc_activedialog.cpp

moc_entitytypebutton.cpp: entitytype.h \
		fieldmap.h \
		fielddescription.h \
		datasource.h \
		stringintturple.h \
		entitytypebutton.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) entitytypebutton.h -o moc_entitytypebutton.cpp

compiler_rcc_make_all: qrc_icons.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_icons.cpp
qrc_icons.cpp: icons.qrc \
		star.png \
		green_dot.png \
		mouse_pointer.png \
		Computer.png
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
		entity.h \
		entitytype.h \
		fieldmap.h \
		fielddescription.h \
		datasource.h \
		stringintturple.h \
		projectstore.h \
		entitytypebutton.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainform.o: mainform.cpp mainform.h \
		activedialog.h \
		entity.h \
		entitytype.h \
		fieldmap.h \
		fielddescription.h \
		datasource.h \
		stringintturple.h \
		projectstore.h \
		entitytypebutton.h \
		ui_mainform.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainform.o mainform.cpp

entity.o: entity.cpp entity.h \
		entitytype.h \
		fieldmap.h \
		fielddescription.h \
		datasource.h \
		stringintturple.h \
		activedialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o entity.o entity.cpp

activedialog.o: activedialog.cpp activedialog.h \
		entity.h \
		entitytype.h \
		fieldmap.h \
		fielddescription.h \
		datasource.h \
		stringintturple.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o activedialog.o activedialog.cpp

entitytype.o: entitytype.cpp entitytype.h \
		fieldmap.h \
		fielddescription.h \
		datasource.h \
		stringintturple.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o entitytype.o entitytype.cpp

entitytypebutton.o: entitytypebutton.cpp entitytypebutton.h \
		entitytype.h \
		fieldmap.h \
		fielddescription.h \
		datasource.h \
		stringintturple.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o entitytypebutton.o entitytypebutton.cpp

fieldmap.o: fieldmap.cpp fieldmap.h \
		fielddescription.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fieldmap.o fieldmap.cpp

projectstore.o: projectstore.cpp projectstore.h \
		entitytype.h \
		fieldmap.h \
		fielddescription.h \
		datasource.h \
		stringintturple.h \
		mysqldatasource.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o projectstore.o projectstore.cpp

stringintturple.o: stringintturple.cpp stringintturple.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o stringintturple.o stringintturple.cpp

datasource.o: datasource.cpp datasource.h \
		stringintturple.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o datasource.o datasource.cpp

mysqldatasource.o: mysqldatasource.cpp datasource.h \
		stringintturple.h \
		mysqldatasource.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mysqldatasource.o mysqldatasource.cpp

moc_mainform.o: moc_mainform.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainform.o moc_mainform.cpp

moc_entity.o: moc_entity.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_entity.o moc_entity.cpp

moc_activedialog.o: moc_activedialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_activedialog.o moc_activedialog.cpp

moc_entitytypebutton.o: moc_entitytypebutton.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_entitytypebutton.o moc_entitytypebutton.cpp

qrc_icons.o: qrc_icons.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_icons.o qrc_icons.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

