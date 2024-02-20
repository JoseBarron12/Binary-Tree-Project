CXXFLAGS += -std=c++11 -Wall -Wextra -Werror -pedantic -I.


all: binarytree


main: binarytree.cc btree.h node.h
	g++ $(CXXFLAGS) -o binarytree binarytree.cc 

clean:
	rm -f binarytree

.PHONY: all clean
