CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJECTS =  src/utils/helpers.o src/methods/searches.o src/methods/sorts.o src/main.o
BINARYS = main sorts searches helpers *.out

main: $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LDFLAGS)

src/%.o: src/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

graphBuilder: main
	@python3 src/utils/graph.py

clean:
	@rm -f $(BINARYS) $(OBJECTS)
