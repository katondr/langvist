PACKAGE = langvist
VERSION	= 0.1
DATE	= $(shell date "+%b%y")
#FLAGS	= -lncurses

EXE	= $(PACKAGE)

all: bindir src/main.cpp
	$(CXX) src/main.cpp $(FLAGS) -o bin/$(EXE)

bindir: 
	mkdir -p bin

run: bin/$(EXE)
	./bin/$(EXE)

clean:
	rm -f bin/$(EXE)
	rmdir bin

retriever:
	$(CXX) src/examples/retriever.cpp -o bin/retriever
