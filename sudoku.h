#include <iostream>
#include <map>
using namespace std;

class Sudoku{
public:
	void giveQuestion();
	void readIn();
	void getElement();
	void solve();
	void changeNum(int a, int b);
	void changeRow(int a, int b);
	void changeCol(int a, int b);
	void rotate(int n);
	void flip(int n);
	void transform();
	map<int,int> sudokuIn;
	static const int sudokuSize = 81;

private:
	bool checkUnity(int arr[]);
};