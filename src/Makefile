CC = gcc
CFLAGS = -O2 -Wall -s
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
TARGET = ../bin/passgen

all: $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p ../bin
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)
