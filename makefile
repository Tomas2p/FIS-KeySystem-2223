CC = g++
CXXFLAGS = -std=c++17 -o 

OBJ0 = src/main.cpp
OBJ1 = src/key.cpp
OBJ2 = src/keysystem.cpp
OBJ3 = src/tools.cpp

OUT = keysystem

all: clean ${OUT}

${OUT}:
	${CC} ${CXXFLAGS} $@ ${OBJ0} ${OBJ1} ${OBJ2} ${OBJ3}

clean:
	rm -f ./${OUT}