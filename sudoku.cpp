#include "sudoku.h"
#include <vector>
#include <cstdlib>
#include <ctime>

void giveQuestion(){

};

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

bool Sudoku::checkUnity(int arr[]){
	int arr_count[9];
	int i;
	for (i=0;i<9;i++){//initialize
		arr_count[i]=0;
	}
	for (i=0;i<9;i++){
		arr_count[arr[i]-1]++;
	}
	for (i=0;i<9;i++){
		if (arr_count[i] > 1){
			return false;
		}
	}
	return true;
};

int Sudoku::getElement(int i){
	return sudokuIn[i];
};

void Sudoku::getRow(int index, int arr[]){
	int i;
	for(i=0;i<9;i++){
		arr_check[i] = arr[intdex+i]
	}
};

void Sudoku::getCol(int index, int arr[]){
	int i;
	for(i=0;i<9;i++){
		arr_check[i] = arr[intdex+(9*i)]
	}
};

void Sudoku::solve(){
	 vector<int> usedNum;
	 int i,j,temp;
	 for(i=0;i<sudokuSize;i+9){
	 	getRow(i,sudokuIn);
	 	for(j=0;j<9;j++){
	 		if(arr_check[j]!=0){
	 			temp=arr_check[j]
	 			usedNum.push_back(temp);
	 		}			
	 	}
	 }
};

bool Sudoku::check_answer(){
	int i;
	for(i=0;i<sudokuSize; i+9){
		getRow(i,answerBoard);
		if(checkUnity(arr_check) == false)
			return false;
	}
	for(i=0;i<9;i++){
		getCol(i,answerBoard);
		if(checkUnity(arr_check) == false)
			return false;
	}
	return true;
};

void Sudoku::changeNum(int a,int b){
	srand(time(NULL));
	int changeNum1,changeNum2;
	int i,count;
	count=rand()%9+1;

	while(count){

		changeNum1=rand()%9+1;
		changeNum2=rand()%9+1;

		while(changeNum1 == changeNum2){
			changeNum2=rand()%9+1;
		}

		for(i=0;i<sudokuSize;i++){
			if(sudokuIn[i] == changeNum2){
				sudokuIn[i] = 0;
			}
		}
		for(i=0;i<sudokuSize;i++){
			if(sudokuIn[i] == changeNum1){
				sudokuIn[i] = changeNum2;
			}
		}
		for(i=0;i<sudokuSize;i++){
			if(sudokuIn[i] == 0){
				sudokuIn[i] = changeNum1;
			}
		}
		count--;
	}
};

void Sudoku::changeCol(){

};

void Sudoku::rotate(){

};

void Sudoku::flip(){

};

void Sudoku::transform(){

};







