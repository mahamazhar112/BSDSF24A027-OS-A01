CC      = gcc
CFLAGS  = -Wall -Wextra -I../include
OBJDIR  = ../obj
BINDIR  = ../bin
TARGET  = $(BINDIR)/client
SRCS    = $(wildcard *.c)
OBJS    = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

LIBNAME       = myutils
STATIC        = ../lib/lib$(LIBNAME).a
LIB_OBJS      = $(OBJDIR)/mystrfunctions.o $(OBJDIR)/myfilefunctions.o
MAIN_OBJ      = $(OBJDIR)/main.o
TARGET_STATIC = $(BINDIR)/client_static

all: $(TARGET) $(TARGET_STATIC)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(STATIC): $(LIB_OBJS)
	ar rcs $@ $^

$(TARGET_STATIC): $(MAIN_OBJ) $(STATIC)
	$(CC) $(MAIN_OBJ) -L../lib -l$(LIBNAME) -o $@

clean:
	rm -f $(OBJDIR)/*.o $(TARGET) $(STATIC) $(TARGET_STATIC)

.PHONY: all clean