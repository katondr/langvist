package = langvist
version	= 0.1
date	= $(shell date "+%b%y")

bin	= $(package)
ldflags	= -lncurses
scrdir	= -I"src/"

all: src/main.cpp
	g++ src/main.cpp -lncurses -o bin/langvist

run: all
	./bin/$(bin)

clean:
	rm -f bin/$()
