CFLAGS=-c -std=c++11
EXE1=t
EXE2=bnt

${EXE1}:		
				@g++ -o ${EXE1} rec_tree.cpp -D DEBUG
