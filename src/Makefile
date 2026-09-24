CC      = gcc
CFLAGS  = -Wall -Wextra -I../include
OBJDIR  = ../obj
BINDIR  = ../bin
TARGET  = $(BINDIR)/client
SRCS    = $(wildcard *.c)
OBJS    = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

LIBNAME        = myutils
STATIC         = ../lib/lib$(LIBNAME).a
LIB_OBJS       = $(OBJDIR)/mystrfunctions.o $(OBJDIR)/myfilefunctions.o
MAIN_OBJ       = $(OBJDIR)/main.o
TARGET_STATIC  = $(BINDIR)/client_static
DYNAMIC        = ../lib/lib$(LIBNAME).so
TARGET_DYNAMIC = $(BINDIR)/client_dynamic
DYN_LIB_OBJS   = $(OBJDIR)/mystrfunctions.pic.o $(OBJDIR)/myfilefunctions.pic.o

all: $(TARGET) $(TARGET_STATIC) $(TARGET_DYNAMIC)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(STATIC): $(LIB_OBJS)
	ar rcs $@ $^

$(TARGET_STATIC): $(MAIN_OBJ) $(STATIC)
	$(CC) $(MAIN_OBJ) $(STATIC) -o $@

$(OBJDIR)/%.pic.o: %.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(DYNAMIC): $(DYN_LIB_OBJS)
	$(CC) -shared -o $@ $^

$(TARGET_DYNAMIC): $(MAIN_OBJ) $(DYNAMIC)
	$(CC) $(MAIN_OBJ) -L../lib -l$(LIBNAME) -o $@

clean:
	rm -f $(OBJDIR)/*.o $(TARGET) $(STATIC) $(TARGET_STATIC) $(DYNAMIC) $(TARGET_DYNAMIC)

.PHONY: all clean