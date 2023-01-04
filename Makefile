WCC=g++
LCC=g++

OUTDIR=bin
OUTFILE=abr

OBJDIR=obj

# Compiler flags
ifeq ($(OS), Windows_NT)
	LCC=wsl g++
	DEL=del
	SEP=\\
else
	DEL=rm
	SEP=/
	WCC=x86_64-w64-mingw32-g++ -m64 -static
endif

ifeq ($(RELEASE),TRUE)
	CFLAGS= -s -O3 -Wall -Wextra
else
	CFLAGS=-g -Wall -Wextra
endif

all : windows linux

windows : obj/main.obj obj/abr.obj
	$(WCC) $(CFLAGS) -o $(OUTDIR)/$(OUTFILE).exe $^

linux : obj/main.o obj/abr.o
	$(LCC) $(CFLAGS) -o $(OUTDIR)/$(OUTFILE).out $^

clean :
	$(DEL) $(OUTDIR)$(SEP)*.exe
	$(DEL) $(OUTDIR)$(SEP)*.out
	$(DEL) $(OBJDIR)$(SEP)*.o
	$(DEL) $(OBJDIR)$(SEP)*.obj
	@echo "Cleaned"

obj/main.o : src/main.cpp header/abr.h
	$(LCC) $(CFLAGS) -o $@ -c $<

obj/main.obj : src/main.cpp header/abr.h
	$(WCC) $(CFLAGS) -o $@ -c $<

obj/abr.o : src/abr.cpp header/abr.h
	$(LCC) $(CFLAGS) -o $@ -c $<

obj/abr.obj : src/abr.cpp header/abr.h
	$(WCC) $(CFLAGS) -o $@ -c $<