#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

gcc := g++ -std=c++17
ln := g++ -std=c++17

melody.cpp : generator.exe
	./generator.exe 

generator.exe : generator.o rtttl_player.o
	$(gcc) generator.o rtttl_player.o -o generator.exe

generator.o : generator.cpp fur_elise.hpp rtttl_player.hpp melody.hpp note_player.hpp note.hpp
	$(gcc) -c generator.cpp -o generator.o

rtttl_player.o : rtttl_player.cpp rtttl_player.hpp note_player.hpp note.hpp 
	$(gcc) -c rtttl_player.cpp -o rtttl_player.o

# source & header files in this project (main.cpp is automatically assumed)


HEADERS += note.hpp
HEADERS += melody.hpp
HEADERS += note_player.hpp
HEADERS += fur_elise.hpp

HEADERS+= note_player_gpio.hpp
SOURCES+= note_player_gpio.cpp

SOURCES += melody.cpp

# other places to look for files for this project
SEARCH  := 

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
