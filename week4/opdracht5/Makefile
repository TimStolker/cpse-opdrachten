#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)

gcc := g++ -std=c++17
ln := g++ -std=c++17

coder.cpp : decode.exe
	./decode.exe 

coder.exe : coder.o 
	$(gcc) coder.o -o coder.exe

coder.o : coder.cpp compressor.hpp decompressor.hpp match.hpp
	$(gcc) -c coder.cpp -o coder.o


SOURCES :=compressed.asm decode.asm

# header files in this project
HEADERS := match.hpp compressor.hpp decompressor.hpp

# other places to look for files for this project
SEARCH  := ../07-library

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
