#include<iostream>
#include<vector>

using namespace std;

bool isValid(vector<string>board, int row, int column) {
	int n = board.size();
	for (int i = 0; i < row; i++)
		if (board[i][column] == 'Q')return false;
	for (int i = row - 1, j = column + 1; i >= 0 && j < n; i--, j++)
	{
		if (board[i][j] == 'Q')return false;
	}
	for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (board[i][j] == 'Q')return false;
	}
	return true;
}

void backtrack(vector<vector<string>> &res,vector<string>& board, int row) {
	if (row == board.size())
	{
		res.push_back(board);
		return;
	}
	int n = board.size();
	for (int i = 0; i < n; i++)
	{
		if (!isValid(board, row, i))continue;
		board[row][i] = 'Q';
		backtrack(res,board, row + 1);
		board[row][i] = '.';
	}
}

vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> res;
	vector<string>board(n, string(n,'.'));
	backtrack(res,board, 0);
	return res;
}

int main()
{
	vector<vector<string>> res=solveNQueens(4);

	for (auto i : res)
	{
		for (auto j : i)
		{
			cout << j <<endl;
		}
		cout << endl;
	}
}