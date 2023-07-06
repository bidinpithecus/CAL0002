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
.PHONY: clean view
clean:
	rm -f $(OBJECTS) $(BINARY)

cleanAll:
	rm -f $(OBJECTS) $(BINARY) data/*

plot: data/dfs.svg data/dijkstra.svg
	cd report/ && pdflatex --shell-escape -interaction=nonstopmode report.tex && cd ..

data/dfs.dot: $(BINARY)
	./$(BINARY)

data/dfs.svg: data/dfs.dot
	dot -Tsvg $< > $@

data/dijkstra.dot: $(BINARY)
	./$(BINARY)

data/dijkstra.svg: data/dijkstra.dot
	dot -Tsvg $< > $@
