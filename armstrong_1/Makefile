CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -g
LDFLAGS = -lm
SRC = armstrong.c main.c 
OBJ = $(SRC:.c=.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET) 
