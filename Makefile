package = langvist
version	= 0.1
date	= $(shell date "+%b%y")

exe	= $(package)

all: bindir src/main.cpp
	$(CXX) src/main.cpp -lncurses -o bin/$(exe)

bindir: 
	mkdir -p bin

run: bin/$(exe)
	./bin/$(exe)

clean:
	rm -f bin/$(exe)
	rmdir bin
