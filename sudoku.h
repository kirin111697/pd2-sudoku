#include <iostream>
#include <cstdio>
using namespace std;

class Sudoku{
public:
	void giveQuestion();
	void readIn();
	bool checkUnity(int arr[]);
	void getRow(int index, int arr[]);
	void getCol(int index, int arr[]);
	void getCell(int index, int arr[]);
	int findZero();
	void getUsedNum(int n);
	void fillBlank(int index);
	void solve();
	bool check_answer();
	void changeNum(int a, int b);
	void changeRow(int a, int b);
	void changeCol(int a, int b);
	void rotate(int n);
	void flip(int n);
	void printOut(int board[]);
	void change();
	void transform();
	static const int sudokuSize = 81;


private:	
	int sudokuIn[sudokuSize];
	int answerBoard[sudokuSize];
	int keepAns[sudokuSize];
	int arr_check[9];
	int usedNum[9];
	int ansCount;
};