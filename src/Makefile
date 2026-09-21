CC      = gcc
CFLAGS  = -Wall -Wextra -I../include
OBJDIR  = ../obj
BINDIR  = ../bin
TARGET  = $(BINDIR)/client
SRCS    = $(wildcard *.c)
OBJS    = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJDIR)/*.o $(TARGET)

.PHONY: all clean