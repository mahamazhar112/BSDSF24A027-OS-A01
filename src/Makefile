# Compiler and flags
CC      = gcc
CFLAGS  = -Wall -Wextra -I../include

# Directories
OBJDIR  = ../obj
BINDIR  = ../bin

# Targets
TARGET         = $(BINDIR)/client
LIBNAME        = myutils
STATIC         = ../lib/lib$(LIBNAME).a
TARGET_STATIC  = $(BINDIR)/client_static
DYNAMIC        = ../lib/lib$(LIBNAME).so
TARGET_DYNAMIC = $(BINDIR)/client_dynamic

# Source and object files
SRCS         = $(wildcard *.c)
OBJS         = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))
LIB_OBJS     = $(OBJDIR)/mystrfunctions.o $(OBJDIR)/myfilefunctions.o
MAIN_OBJ     = $(OBJDIR)/main.o
DYN_LIB_OBJS = $(OBJDIR)/mystrfunctions.pic.o $(OBJDIR)/myfilefunctions.pic.o

all: $(TARGET) $(TARGET_STATIC) $(TARGET_DYNAMIC)
	@echo "Build complete."

# Build the plain multi-file executable
$(TARGET): $(OBJS)
	$(CC) $^ -o $@

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build and link the static library
$(STATIC): $(LIB_OBJS)
	ar rcs $@ $^

$(TARGET_STATIC): $(MAIN_OBJ) $(STATIC)
	$(CC) $(MAIN_OBJ) $(STATIC) -o $@

# Build and link the dynamic library
$(OBJDIR)/%.pic.o: %.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(DYNAMIC): $(DYN_LIB_OBJS)
	$(CC) -shared -o $@ $^

$(TARGET_DYNAMIC): $(MAIN_OBJ) $(DYNAMIC)
	$(CC) $(MAIN_OBJ) -L../lib -l$(LIBNAME) -o $@

clean:
	@echo "Cleaning..."
	rm -f $(OBJDIR)/*.o $(TARGET) $(STATIC) $(TARGET_STATIC) $(DYNAMIC) $(TARGET_DYNAMIC)

.PHONY: all clean