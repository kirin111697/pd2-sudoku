#include "Sudoku.h"
using namespace std;

int main(){
	Sudoku sudoku;
	sudoku.readIn();
	sudoku.solve();
	return 0;
}