# $Id: Makefile,v 67230a3743ca 2010/10/18 10:52:20 michael $

# Set an environment varible $(MAKE) to the name of the make command
# on your machine, e.g. 'make' on UNIX and 'mingw32-make' on windows.
# Fallback default is UNIX make.

ifeq ($(MAKE),)
	MAKE=make
endif

# Ditto for QMAKE
ifeq ($(QMAKE),)
	QMAKE=qmake
endif

all: tutorial1D

tutorial1D: Makefile.tutorial1D
	$(MAKE) -f Makefile.tutorial1D

Makefile.tutorial1D: tutorial1D.pro
	$(QMAKE) -o $@ $< 

clean:
	$(MAKE) -f Makefile.tutorial1D clean
ifeq ($(MAKE),make)
	touch tutorial1D.pro
else
	copy /b tutorial1D.pro +,,
endif

# finis
