#include "Sudoku.h"
using namespace std;

int main(){
	Sudoku sudoku;
	sudoku.readIn();
	sudoku.transform();
	cout << endl << endl;
	sudoku.solve();
	cout << endl << endl;

	return 0;
}