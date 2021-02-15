# $Id$

# Set an environment varible $(MAKE) to the name of the make command
# on your machine, e.g. 'make' on UNIX and 'mingw32-make' on windows.
# Fallback default is UNIX make.

ifeq ($(MAKE),)
	MAKE=make
endif

# Ditto for QMAKE
ifeq ($(QMAKE),)
	QMAKE=qmake-qt4
endif

all: uncoupleCle

uncoupleCle: Makefile.uncoupleCle
	$(MAKE) -f Makefile.uncoupleCle

uncoupleCle2: Makefile.uncoupleCle2
	$(MAKE) -f Makefile.uncoupleCle2

Makefile.uncoupleCle: uncoupleCle.pro
	$(QMAKE) -o $@ $< 

clean:
	$(MAKE) -f Makefile.uncoupleCle clean
ifeq ($(MAKE),make)
	touch uncoupleCle.pro
else
	copy /b uncoupleCle.pro +,,
endif

# finis
