CFLAGS=-c -std=c++11
EXE1=rec_tree
EXE2=ex5
EXE3=ex6
EXE4=ex8
CLEAN=clean

all:			${EXE1} ${EXE2} ${EXE3} ${CLEAN} ${EXE4}

${CLEAN}:		
				@g++ -o ${CLEAN} clean.cpp

${EXE1}:		rec_tree.o
				@g++ -o ${EXE1} rec_tree.o

${EXE2}:		ex5.o
				@g++ -o ${EXE2} ex5.o

${EXE3}:		ex6.o		
				@g++ -o ${EXE3} ex6.o

${EXE4}:		ex8.o
				@g++ -o ${EXE4} ex8.o

rec_tree.o:		rec_tree.cpp
				@g++ ${CFLAGS} rec_tree.cpp -D DEBUG

ex5.o:			ex5.cpp
				@g++ ${CFLAGS} ex5.cpp -D DEBUG

ex6.o:			generic_tree.hpp ex6.cpp
				@g++ ${CFLAGS} ex6.cpp -D DEBUG

ex8.o:			generic_tree.hpp ex8.cpp
				@g++ ${CFLAGS} ex8.cpp -D DEBUG