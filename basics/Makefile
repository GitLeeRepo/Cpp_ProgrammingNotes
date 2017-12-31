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

EXE = sandbox01 datatype_ex1 cout_ex1 array_ex1 string_ex1 string_ex2 cin_ex1 \
      struct_ex1 class_ex1 class_ex2 class_ex3 except_ex1 template_ex1 \
      func_ex1 switch_ex1 oper_overload_ex1

EXE2 = module_ex1a
EXE3 = template_ex2a
INCFILES =
INCFILES2 = Vector.h
INCFILES3 = VectorT.h
LDLIBS =
LDLIBS2 = module_ex1b.o 
LDLIBS3 = template_ex2b.o
CC=g++
CPPFLAGS = -std=c++11 -gdwarf -Wall
#CPPFLAGS =  -gdwarf -Wall

.PHONY: info clean

all: info $(LDLIBS) $(LDLIBS2) $(EXE) $(EXE2) $(EXE3)

info:
	@echo "Info: make for: $(EXE)"

# compile happens here
$(EXE): $(INCFILES) 

$(EXE2): $(INCFILES2) $(LDLIBS2) 

$(EXE3): $(INCFILES3) $(LDLIBS3) 

# compile common object tile
$(LDLIBS): $(INCFILES) 

$(LDLIBS2): $(INCFILES2) 

$(LDLIBS3): $(INCFILES3) 

clean:
	$(RM) $(EXE) $(EXE2) $(EXE3) *.o
