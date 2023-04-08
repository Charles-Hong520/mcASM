ifdef CLANG
CC = clang++
else
CC = g++
endif

CPPFLAGS = -std=c++17 -Wall -Werror

all: mcasm

mcasm: src/Parser.h src/interpreter.cpp
	$(CC) $(CPPFLAGS) src/interpreter.cpp -o mcasm

clean:
	rm mcasm