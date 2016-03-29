#include <iostream>
#include <map>
using namespace std;

class Sudoku{
public:
	void giveQuestion();
	void readIn();
	void solve();
	void changeNum(int a, int b);
	void changeRow(int a, int b);
	void changeCol(int a, int b);
	void rotate(int n);
	void flip(int n);
	void transform();
	static const int sudokuSize = 81;
	int getElement(int i);
	bool checkUnity(int arr[]);
	void getRow(int index, int arr[]);
	void getCol(int index, int arr[]);
	bool check_answer();
	int answerBoard[sudokuSize];

private:	
	int sudokuIn[sudokuSize];
	int arr_check[9];
};