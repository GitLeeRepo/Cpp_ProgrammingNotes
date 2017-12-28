# Simple make for compiling individual C files into individual executables of 
# the same name. Intended for compiling simple demo/concept programs with 
# multiple executables in same directory This relies on implicit variables 
# and default actions to do the compile of the $(EXE) target. The implicit CC 
# and CFLAGS are redefined here, while RM uses the default 'rm -f'. Only 
# recompiles the specified files and header if they have changed since last 
# compile

# common library and include directory
COMMON_DIR = ../../commonlib
COMMON_LIB = $(COMMON_DIR)/common.o
COMMON_INCL = $(COMMON_DIR)/common.h

EXE = sandbox01 datatype_ex1 cout_ex1 array_ex1 string_ex1
INCFILES = 
LDLIBS =
CC=g++
CPPFLAGS = -std=c++11 -gdwarf -Wall
#CPPFLAGS =  -gdwarf -Wall

.PHONY: info clean

all: info $(LDLIBS) $(EXE)

info:
	@echo "Info: make for: $(EXE)"

# compile happens here
$(EXE): $(INCFILES) 

# compile common object tile
$(LDLIBS): $(INCFILES) 

clean:
	$(RM) $(EXE) *.o