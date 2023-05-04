CPP = g++
CPPFLAGS = -Wall -Wextra -std=c++11
LDFLAGS = -lm
SRC_DIR = src
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(SRC_DIR)/%.o, $(wildcard $(SRC_DIR)/*.cpp))
BINARY = main

all: $(BINARY)

run: $(BINARY)
	./$^

main: $(OBJECTS)
	$(CPP) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/%.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

# Clean up object files and executable
.PHONY: clean clear
clean:
	rm -f $(OBJECTS) $(BINARY)

plot: data/graph.svg

data/graph.dot: $(BINARY)
	./$(BINARY)

data/graph.svg: data/graph.dot
	dot -Tsvg $< > $@
	nomacs $@
