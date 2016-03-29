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
		arr_check[i] = arr[index+i];
	}
};

void Sudoku::getCol(int index, int arr[]){
	int i;
	for(i=0;i<9;i++){
		arr_check[i] = arr[index+(9*i)];
	}
};

void Sudoku::solve(){
	 vector<int> usedNum;
	 int i,j,temp;
	 for(i=0;i<sudokuSize;i+=9){
	 	getRow(i,sudokuIn);
	 	for(j=0;j<9;j++){
	 		if(arr_check[j]!=0){
	 			temp=arr_check[j];
	 			usedNum.push_back(temp);
	 		}			
	 	}
	 }
};

bool Sudoku::check_answer(){
	int i;
	for(i=0;i<sudokuSize;i+=9){
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
	int i;
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

void Sudoku::rotate(int n){
	int turnTime=(n%4);
	int copy[81];
	int i,j;

	for(i=0;i<81;i++){
		copy[i]=sudokuIn[i];
	}

	switch(turnTime){
		case 0:
			break;

		case 1:
			for(i=0;i<9;i++){
				getCol(i,copy);
				for(j=0;j<9;j++){
					sudokuIn[i*9+j] = arr_check[8-j];
				}
			}
			break;

		case 2:
			for(i=8;i>=0;i--){
				getRow(i*9,copy);
				for(j=0;j<9;j++){
					sudokuIn[(8-i)*9+j] = arr_check[8-j];
				}
			}
			break;

		case 3:
			for(i=8;i>=0;i--){
				getCol(i,copy);
				for(j=0;j<9;j++){
					sudokuIn[(8-i)*9+j] = arr_check[j];
				}
			}
			break;
	}
};

void Sudoku::flip(int n){
	int i,j,count;
	int copy[81];

	for(i=0;i<81;i++){
		copy[i]=sudokuIn[i];
	}
	
	switch(n){
		case 0://vertical
			for(i=0;i<9;i++){
				getRow(i*9,copy);
				count=0;
				for(j=(8-i)*9;j<((8-i)*9+9);j++){
					sudokuIn[j]=arr_check[count];
					count++;
				}
			}
			break;
		case 1:
			for(i=0;i<9;i++){
				getCol(i,copy);
				count=0;
				for(j=8-i;j<(8-i)+73;j+=9){
					sudokuIn[j]=arr_check[count];
					count++;
				}
			}
			break;
	}
};

void Sudoku::transform(){

};







