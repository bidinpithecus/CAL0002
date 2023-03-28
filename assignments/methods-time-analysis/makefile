CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJECTS =  src/utils/helpers.o src/methods/searches.o src/methods/sorts.o src/main.o
BINARYS = main sorts searches helpers *.out

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LDFLAGS)
	./main

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

plot: main
	python3 src/utils/plot.py

clean:
	rm -f $(BINARYS) $(OBJECTS)
