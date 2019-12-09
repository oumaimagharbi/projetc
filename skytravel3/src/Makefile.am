## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = skytravel3

skytravel3_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	who.c who.h \
	rech.c rech.h \
	rechr.c rechr.h \
	afficher_plane.c afficher_plane.h \
	ameni.c ameni.h \
	bilel.c bilel.h \
	reserver.c reserver.h 

skytravel3_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

