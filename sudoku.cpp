#include "sudoku.h"

void Sudoku::readIn(){
	int i,num;
	while(1){
		for (i=0;i<81;i++){
			cin >> num;
			sudokuIn[i] = num;
		}
		break;
	}
};

/*bool Sudoku::checkUnity(int arr[]){
	int arr_count[9];
	int i;
	for (i=0;i<9;i++){//initialize
		arr_count[i]=0;
	}
	for (i=0;i<9;i++){
		arr_count[arr[i]-1]++;
	}
};

void Sudoku::solve(){

};*/



