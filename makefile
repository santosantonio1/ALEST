CFLAGS=-c -std=c++11
EXE1=t
EXE2=ex5

${EXE1}:		
				@g++ -o ${EXE1} rec_tree.cpp -D DEBUG
${EXE2}:		
				@g++ -o ${EXE2} ex5.cpp -D DEBUG