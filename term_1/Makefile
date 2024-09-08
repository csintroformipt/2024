CC = gcc
CXX = g++
CFLAGS = -std=c99 -g -Wall -Wextra
CXXFLAGS = -std=c++17 -g -Wall -Wextra -pedantic

objects_cpp = bin/ex_2\
		bin/ex_3\
		bin/ex_4\
		bin/ex_5\
		bin/ex_6\
		bin/ex_7\
		bin/ex_8\
		bin/ex_9\
		bin/ex_10
		#bin/ex_12 for ex_12 please see ex_4

objects_c = bin/ex_1\
		bin/ex_11

.PHONY: all
all: $(objects_c) $(objects_cpp)
	

$(objects_c): bin/%: wk_01/%.c
	mkdir -p bin
	$(CC) $(CFLAGS) -o $@ $<

$(objects_cpp): bin/%: wk_01/%.cpp
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o $@ $<