CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -g
LDFLAGS = -lm

all: armstrong

armstrong: armstrong.o main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

armstrong.o: armstrong.c armstrong.h
	$(CC) $(CFLAGS) -c $<

main.o: main.c armstrong.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o armstrong
