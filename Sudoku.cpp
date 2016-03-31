#include "Sudoku.h"
#include <cstdlib>
#include <ctime>

void Sudoku::giveQuestion(){
	int i;
	int cASE,way;
	
	int board1[81]={5,2,0,0,7,0,0,0,0,0,0,0,0,0,0,0,3,7,0,8,7,6,9,5,4,0,2,1,3,2,8,6,7,9,0,0,0,0,5,2,0,1,8,0,0,0,0,8,5,3,9,7,2,1,8,0,1,3,5,6,2,9,0,6,4,0,0,0,0,0,0,0,0,0,0,0,8,0,0,7,6};
	int board2[81]={0,0,0,5,1,2,0,0,6,0,0,0,0,0,0,5,0,0,0,4,0,0,9,8,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0,0,0,3,2,0,3,7,0,0,0,0,0,0,0,0,0,5,9,4,0,7,1,0,0,3,0,0,0,5,0,0,0,8,0,0,0,0,0,0,0,3};
	int board3[81]={0,0,9,0,0,7,0,0,6,8,0,0,0,0,0,0,3,0,0,4,7,0,0,0,0,0,2,0,0,0,0,1,8,0,0,0,0,5,0,3,7,0,0,0,0,0,0,0,0,5,0,2,4,3,6,3,0,0,8,0,0,1,0,0,0,4,0,0,0,0,2,0,7,1,0,0,4,0,0,0,0};
	int board4[81]={0,4,8,1,5,0,0,0,0,1,5,0,0,0,7,0,0,9,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,7,6,0,2,0,4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,5,0,7,0,2,4,0,0,0,0,2,0,3,6,0,5,0,0,0,0,1,0,0,0,0};

	srand(time(NULL));
	cASE=rand()%4+1;
	switch(cASE){
		case 1:
			for(i=0;i<81;i++){
				sudokuIn[i]=board1[i];
			}
			transform();
			break;

		case 2:
			for(i=0;i<81;i++){
				sudokuIn[i]=board2[i];
			}
			transform();
			break;

		case 3:
			for(i=0;i<81;i++){
				sudokuIn[i]=board3[i];
			}
			transform();
			break;

		case 4:
			for(i=0;i<81;i++){
				sudokuIn[i]=board4[i];
			}
			transform();
			break;
	}

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
		if(arr[i] != 0){
			arr_count[arr[i]-1]++;
		}
		else{
			continue;
		}	
	}
	for (i=0;i<9;i++){
		if (arr_count[i] > 1){
			return false;
		}
	}
	return true;
};

void Sudoku::getRow(int index, int arr[]){
	int i;
	for(i=0;i<9;i++){
		arr_check[i] = arr[index-(index%9)+i];
	}		
};

void Sudoku::getCol(int index, int arr[]){
	int i;
	for(i=0;i<9;i++){
		arr_check[i] = arr[index-(index/9*9)+(9*i)];
	}
};

void Sudoku::getCell(int index,int arr[]){
	int row,newIndex,i;
	row=(index/9);
	if(row == 0 || row == 3 || row == 6){
		for(i=0;i<9;i++){
			newIndex=(index-(index%3))+i/3*9+i%3;
			arr_check[i]=arr[newIndex];
		}
	}
	else if (row == 1 || row == 4 || row == 7){
		for(i=0;i<9;i++){
			newIndex=(index-(index%3)-9)+i/3*9+i%3;
			arr_check[i]=arr[newIndex];
		}
	}
	else{
		for(i=0;i<9;i++){
			newIndex=(index-(index%3)-18)+i/3*9+i%3;
			arr_check[i]=arr[newIndex];
		}
	}
};

int Sudoku::findZero(){
	int i;
	for(i=0;i<81;i++){
		if(answerBoard[i] == 0){
			return i;
		}
	}
	return -1;
};

void Sudoku::getUsedNum(int n){
	int i,j;
	getRow(n,answerBoard);

	j=n/9;

	for(i=0;i<9;i++){//initialize
		usedNum[j][i]=0;
	}

	for(i=0;i<9;i++){
		if(arr_check[i]!=0){
	 		usedNum[j][arr_check[i]-1]=1;
	 	}
	}
};

void Sudoku::fillBlank(){
	int i,j,zero,next;//zero:現在要填的格(0~80),next:再下一格要填的
	zero = findZero();
	//getUsedNum(zero);//取得可填數字資訊

	//cout << "at the beginning UsedNum : " << endl;
	/*for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			cout << usedNum[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/

	for(i=0;i<9;i++){
		/*if(usedNum[zero/9][i]!=0){
			continue;
		}*/
		
			answerBoard[zero]=i+1;
			/*cout << "answerBoard" << endl; 
			printOut(answerBoard);
			cout << endl << endl;*/
			//getUsedNum(zero);
			if(check_answer(zero)==false){
				continue;//不用更換記號因為繼續迴圈後會往更大的數字嘗試
			}
			else{
				//usedNum[zero/9][i-1]=1; 
				next = findZero();
				if(next == -1 && ansCount <= 1){
					ansCount++;
					for(i=0;i<81;i++){
						keepAns[i]=answerBoard[i];
					}
				}
				else if(next == -1 && ansCount > 1){
					cout << "2" << endl;
					return;
				}
				else{
					fillBlank();
				}
			}
		
	}

	if(ansCount > 1){
		return;
	}

	for(i=80;i>=0;i--){
		if(answerBoard[i]!=sudokuIn[i]){
			//temp = answerBoard[i];
			answerBoard[i] = 0;
			/*cout << "answerBoard update :" << endl;
			printOut(answerBoard);
			cout << endl << endl;*/
			//usedNum[i/9][temp-1]= 0;
			//getUsedNum(zero);
			//cout << "at the end UsedNum : " << endl;
			/*for(i=0;i<9;i++){
				for(j=0;j<9;j++){
					cout << usedNum[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;*/
			break;
		}
	}

};

void Sudoku::solve(){
	int i,j;
	ansCount=0;

	for(i=0;i<81;i=i+9){//test if the sudoku can be solved
		getRow(i,sudokuIn);
		if(checkUnity(arr_check)==false){
			cout << "0"
				 << endl;
	 		return;
	 	}
	 	getCol(i,sudokuIn);
	 	if(checkUnity(arr_check)==false){
			cout << "0"
				 << endl;
	 		return;
	 	}
	 	getCell(i,sudokuIn);
	 	if(checkUnity(arr_check)==false){
			cout << "0"
				 << endl;
	 		return;
	 	}
	}

	for(i=0;i<81;i++){
		answerBoard[i]=sudokuIn[i];
	}

	/*for(i=0;i<9;i++){//initialize
		for(j=0;j<9;j++){
			usedNum[i][j]=0;
		}
	}*/

	fillBlank();

	if(ansCount==1){
		cout << "1" << endl;
		printOut(keepAns);
	}
	else if(ansCount==0)
		cout << "0";
	else if(ansCount==2){
		cout << "2";
	}
};

bool Sudoku::check_answer(int n){

	getRow(n,answerBoard);
	if(checkUnity(arr_check) == false)
		return false;

	getCol(n,answerBoard);
	if(checkUnity(arr_check) == false)
		return false;

	getCell(n,answerBoard);
	if(checkUnity(arr_check) == false)
		return false;

	return true;
};

void Sudoku::changeNum(int a,int b){
	int i;
	for(i=0;i<sudokuSize;i++){
		if(sudokuIn[i] == b){
			sudokuIn[i] = -1;
		}
	}
	for(i=0;i<sudokuSize;i++){
		if(sudokuIn[i] == a){
			sudokuIn[i] = b;
		}
	}
	for(i=0;i<sudokuSize;i++){
		if(sudokuIn[i] == -1){
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
	int low,high,index,i;
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

void Sudoku::printOut(int board[]){
	int i;
	for (i=0;i<81;i++){
		if ((i+1)%9 == 0){
			cout << board[i]
				 << endl;
		}
		else{
			cout << board[i]
				 << " ";
		}
	}
}

void Sudoku::change(){
	srand(time(NULL));
	int a,b,n;
	
	//cout << " changeNum " << endl;
	a = rand()%9+1;
	b = rand()%9+1;
	while(a == b || b == 0){			
		b=rand()%9+1;
	}	
	changeNum(a,b);
	
	//cout << " changeRow " << endl;
	a = rand()%3;
	b = rand()%3;
	while(a == b){			
		b=rand()%3;
	}
	changeRow(a,b);
	
	//cout << " changeCol " << endl;
	a = rand()%3;
	b = rand()%3;
	while(a == b){			
		b=rand()%3;
	}
	changeCol(a,b);
	
	//cout << " FLIP " << endl;
	n = rand()%2;
	flip(n);
	
	//cout << " ROTATE " << endl;
	n = rand()%101;
	rotate(n);
}

void Sudoku::transform(){
	//printOut(sudokuIn);
	//cout << endl << endl;
	change();
	printOut(sudokuIn);
	//cout << endl << endl;
};