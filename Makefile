a.out : main.o sudoku.o
	g++ main.o sudoku.o

sudoku.o : sudoku.h sudoku.cpp
	g++ -c sudoku.cpp

main.o : main.cpp sudoku.h
	g++ -c main.cpp

clean:
	rm *.o