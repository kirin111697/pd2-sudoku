all: Sudoku.o giveQuestion.cpp solve.cpp transform.cpp
	g++ -o giveQuestion giveQuestion.cpp Sudoku.o
	g++ -o solve solve.cpp Sudoku.o
	g++ -o transform transform.cpp Sudoku.o

sudoku.o : Sudoku.h Sudoku.cpp
	g++ -c Sudoku.cpp

clean:
	rm *.o