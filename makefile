# -*- MakeFile -*-

#target: dependencies
#	commands

# compiler
CC = gcc
CC_FLAGS = -c

# project name
projname = netmap.exe 

# sources directories
src_dirs = ./src/TADs
# include directories
inc_dirs = ./src/TADs
# object directorie
obj_dir	= ./obj

# sources
srcs := $(wildcard $(src_dirs)/*.c)
includes := $(wildcard $(inc_dirs)/*.h)
# object files
objs:= $(srcs:.c =$(obj_dir).o)



all: $(projname)

$(projname): $(objs)
	$(CC) -o $@ $^

%.o: %.c %.h
	$(CC) -o $@ $< $(CC_FLAGS)

main.o: main.c $(includes)
	$(cc) -o $@ $< $(CC_FLAGS)

clean:
	
	$(RM) *.o $(projname)

ifeq ($(OS),Windows_NT)
    RM = del /F /Q 
    RMDIR = -RMDIR /S /Q
    MKDIR = -mkdir
    ERRIGNORE = 2>NUL || true
    SEP=\\
else
    RM = rm -rf 
    RMDIR = rm -rf 
    MKDIR = mkdir -p
    ERRIGNORE = 2>/dev/null
    SEP=/
endif