# Location of test files
TST = $(wildcard tst/*.cpp)

# Location of source files
SRCS = $(wildcard src/*.cpp src/EGLTest/*.cpp)

# Headers for sources
HDRS = $(wildcard src/*.hpp src/EGLTest/*.hpp)

# Project Name
PROJ = TemplateProject

# Compiler
CC = g++

# Expand the contents of source and change the cpp with an o
OBJS = $(SRCS:.cpp=.o)

# Name of the application
APP = $(PROJ).bin
CFLAGS = -c -g -Wall -I/opt/vc/include -I/usr/local/include -I/opt/vc/include/interface/vcos/pthreads -I./include/
ifeq (,$(findstring CYGWIN,$(shell uname)))
  LDFLAGS = -L/opt/local/lib -L/opt/vc/lib -L./lib
else
  LDFLAGS = -L/opt/local/lib -enable-auto-import -L/opt/vc/lib -L./lib
endif

# Libraries to link with
LIBS = -lGLESv2 -lncurses -lcppunit -ldl -lGL -lGLU -lglut -ljpeg -lcommon

all: lib $(APP)
	./$(APP)
$(APP): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(APP) $(LIBS)

%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f src/*.o tst/*.o *.bin src/EGLTest/*.o ./*.a

test:	clean
	make -f MakeTest all_t
