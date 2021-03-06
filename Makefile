#Makefile Mips R2000 developed by Igor Loi
#v 1.0 2004/12/05 21:42 Diee Cagliari
# Thanks to Nicolai Ascanium from IMM

TARGET_ARCH = linux

CC     = g++
OPT    = -O3
DEBUG  = -g
OTHER  = -Wall -Wno-deprecated
CFLAGS = $(OPT) $(OTHER)
# CFLAGS = $(DEBUG) $(OTHER)
MODULE = adder




SRCS = main.cpp clockgen.cpp Control.cpp MemInstruction.cpp Breg.cpp Ula.cpp MemData.cpp Processor.cpp
	   


	   
OBJS 	= $(SRCS:.cpp=.o)
DEPS	= $(SRCS:.cpp=.d)


%.o : %.cpp
	$(CC) $(INCDIR) $(LIBDIR) $(EXTRA) $(CFLAGS) -c -o $@ $<


$(MODULE): $(OBJS)
	$(CC) $(CFLAGS) $(INCDIR) $(LIBDIR) -o $@ $(OBJS) $(LIBS) 2>&1 | c++filt


include ./Makefile.defs
