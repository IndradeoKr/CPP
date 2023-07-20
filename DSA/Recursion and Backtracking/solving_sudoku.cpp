#include <bits/stdc++.h>
using namespace std;

bool helper(int mtrix[9][9], int i, int j, int n, int number)
{
	for(int x = 0; x < n; x++)
	{
		//row and column check
		if(mtrix[x][j] == number || mtrix[i][x] == number)
			return false;
	}
	int rootN = sqrt(n);
	int stX = (i/rootN)*rootN;
	int stY = (j/rootN)*rootN;
	for(int x = stX; x < stX+rootN; x++)
	{
		for(int y = stY; y < stY+rootN; y++)
		{
			if(mtrix[x][y] == number)
				return false;
		}
	}
	return true;
}

bool solveSudoku(int mtrix[9][9], int i, int j, int n)
{
	//Base case
	if(i == n)
	{
		//Print solution matrix.
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cout << mtrix[i][j] << " ";
			}
			cout << endl;
		}
		return true;
	}
	// If row ends
	if(j == n)
		return solveSudoku(mtrix, i+1, 0, n);
	//Skip the pre-filled cells
	if(mtrix[i][j] != 0)
		return solveSudoku(mtrix, i, j+1, n);
	//Main recursion case
	for(int number = 0; number <= n; number++)
	{
		if(helper(mtrix, i, j, n, number))
		{
			mtrix[i][j] = number;
			
			bool couldWeSolve = solveSudoku(mtrix, i, j+1, n);
			if(couldWeSolve == true)
				return true;
		}
	}
	//backtracking
	mtrix[i][j] = 0;
	return false;
}

int main()
{
	int mtrix[9][9] = {{5,3,0,0,7,0,0,0,0},
					   {6,0,0,1,9,5,0,0,0},
					   {0,9,8,0,0,0,0,6,0},
					   {8,0,0,0,6,0,0,0,3},
					   {4,0,0,8,0,3,0,0,1},
					   {7,0,0,0,2,0,0,0,6},
					   {0,6,0,0,0,0,2,8,0},
					   {0,0,0,4,1,9,0,0,5},
					   {0,0,0,0,8,0,0,7,9}};
					   
	solveSudoku(mtrix, 0, 0, 9);
	
	return 0;
}