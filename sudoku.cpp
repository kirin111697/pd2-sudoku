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
	for(i=0;i<sudokuSize;i++){
		if(sudokuIn[i] == b){
			sudokuIn[i] = 0;
		}
	}
	for(i=0;i<sudokuSize;i++){
		if(sudokuIn[i] == a){
			sudokuIn[i] = b;
		}
	}
	for(i=0;i<sudokuSize;i++){
		if(sudokuIn[i] == 0){
			sudokuIn[i] = a;
		}
	}
};

void Sudoku::changeRow(int a,int b){
	int temp[27];
	int low,high,i;
	if(a>b){
		high=a;
		low=b;
	}
	else{
		high=b;
		low=a;
	}

	if(low == 0 && high == 1){
		for(i=0;i<27;i++){
			temp[i]=sudokuIn[i];
			sudokuIn[i]=sudokuIn[i+27];
			sudokuIn[i+27]=temp[i];
		}
	}
	else if(low == 1 && high == 2){
		for(i=27;i<54;i++){
			temp[i-27]=sudokuIn[i];
			sudokuIn[i]=sudokuIn[i+27];
			sudokuIn[i+27]=temp[i-27];
		}
	}
	else if(low == 0 && high == 2){
		for(i=0;i<27;i++){
			temp[i]=sudokuIn[i];
			sudokuIn[i]=sudokuIn[i+54];
			sudokuIn[i+54]=temp[i];
		}
	}
};

void Sudoku::changeCol(int a,int b){
	int temp[27];
	int low,high,i,index;
	if(a>b){
		high=a;
		low=b;
	}
	else{
		high=b;
		low=a;
	}

	if(low == 0 && high == 1){
		for(i=0;i<27;i++){
			index=(i/3)*9+(i%3);
			temp[i]=sudokuIn[index];
			sudokuIn[index]=sudokuIn[index+3];
			sudokuIn[index+3]=temp[i];
		}
	}
	else if(low == 1 && high == 2){
		for(i=0;i<27;i++){
			index=(i/3)*9+(i%3);
			temp[i]=sudokuIn[index+3];
			sudokuIn[index+3]=sudokuIn[index+6];
			sudokuIn[index+6]=temp[i];
		}
	}
	else if(low == 0 && high == 2){
		for(i=0;i<27;i++){
			index=(i/3)*9+(i%3);
			temp[i]=sudokuIn[index];
			sudokuIn[index]=sudokuIn[index+6];
			sudokuIn[index+6]=temp[i];
		}
	}
};

void Sudoku::rotate(){

};

void Sudoku::flip(){

};

void Sudoku::transform(){

};







