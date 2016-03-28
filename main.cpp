#include <iostream>
#include "sudoku.h"
using namespace std;

int main(){
	Sudoku sudoku;

	sudoku.readIn();
	int i;
	for (i=0;i<81;i++){
		if ((i+1)%9 == 0){
			cout << sudoku.sudokuIn[i]
				 << endl;
		}
		else{
			cout << sudoku.sudokuIn[i]
				 << "  ";
		}
	}
	return 0;
}