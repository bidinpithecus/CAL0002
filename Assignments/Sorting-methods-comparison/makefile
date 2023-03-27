CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJECTS =  src/helpers.o src/searches.o src/sorts.o src/main.o
BINARYS = main sorts searches helpers *.out

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LDFLAGS)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BINARYS) $(OBJECTS)
