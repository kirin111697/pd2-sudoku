#include <iostream>
#include "sudoku.h"
using namespace std;

int main(){
	Sudoku sudoku;

	sudoku.readIn();
	int i;
	for (i=0;i<81;i++){
		if ((i+1)%9 == 0){
			cout << sudoku.getElement(i)
				 << endl;
		}
		else{
			cout << sudoku.getElement(i)
				 << " ";
		}
	}

	cout << endl << endl;
	
	int arr_check[9]={0};

	for(i=0;i<9;i++){
		arr_check[i] = sudoku.getElement(i);
		cout << arr_check[i]
			 << " ";
	}
	cout << endl;
	cout << sudoku.checkUnity(arr_check);
	return 0;
}