#include "IsValidSudoku.h"


void IsValidSudoku::test(void)
{
	vector<vector<char> > vec;
	ifstream fin("E://Algorithms//Lintcode//Lintcode//fileinput//sudoku_input.txt");
	
	for (int i = 0; i < 9; i++)
	{
		vector<char> a;
		a.clear();
		for (int j = 0; j < 9; j++)
		{
			char c;
			fin >> c;
			a.push_back(c);
		}
		vec.push_back(a);
	}
	/*
	for (int i = 0; i < vec[0].size(); i++)
	{
		for (int j = 0; j < vec.size(); j++)
		{
			cout << vec[i][j];
		}
		cout << endl;
	}*/

	if (isValidSudoku(vec))
		cout << "Yes";
	else
		cout << "No";
}

bool IsValidSudoku::isValidSudoku(const vector<vector<char> > &board)
{
	int row = board.size();
	int col = board[0].size();

	int a[10] = { 0 };

	map<char, bool> checkmap;
	//计算 行 是否符合数独的标准
	//for (vector<vector<char> >::iterator iter = board.begin(); iter != board.end(); ++iter)
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			switch (board[i][j])
			{
			case '1':a[1]++; if (a[1] == 2) return false; break;
			case '2':a[2]++; if (a[2] == 2) return false; break;
			case '3':a[3]++; if (a[3] == 2) return false; break;
			case '4':a[4]++; if (a[4] == 2) return false; break;
			case '5':a[5]++; if (a[5] == 2) return false; break;
			case '6':a[6]++; if (a[6] == 2) return false; break;
			case '7':a[7]++; if (a[7] == 2) return false; break;
			case '8':a[8]++; if (a[8] == 2) return false; break;
			case '9':a[9]++; if (a[9] == 2) return false; break;
		

			}
		}
		for (int j = 1; j < 10; j++)
		{
			a[j] = 0;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			switch (board[j][i])
			{
			case '1':a[1]++; if (a[1] == 2) return false; break;
			case '2':a[2]++; if (a[2] == 2) return false; break;
			case '3':a[3]++; if (a[3] == 2) return false; break;
			case '4':a[4]++; if (a[4] == 2) return false; break;
			case '5':a[5]++; if (a[5] == 2) return false; break;
			case '6':a[6]++; if (a[6] == 2) return false; break;
			case '7':a[7]++; if (a[7] == 2) return false; break;
			case '8':a[8]++; if (a[8] == 2) return false; break;
			case '9':a[9]++; if (a[9] == 2) return false; break;


			}
		}
		for (int j = 1; j < 10; j++)
		{
			a[j] = 0;
		}
	}

	for (int i = 0; i < 9; i += 3)
	{
		for (int j = 0; j < 9; j += 3)
		{
			for (int m = 0; m < 3; m++)
			{
				for (int n = 0; n < 3; n++)
				{
					switch (board[i + m][j + n])
					{
					case '1':a[1]++; if (a[1] == 2) return false; break;
					case '2':a[2]++; if (a[2] == 2) return false; break;
					case '3':a[3]++; if (a[3] == 2) return false; break;
					case '4':a[4]++; if (a[4] == 2) return false; break;
					case '5':a[5]++; if (a[5] == 2) return false; break;
					case '6':a[6]++; if (a[6] == 2) return false; break;
					case '7':a[7]++; if (a[7] == 2) return false; break;
					case '8':a[8]++; if (a[8] == 2) return false; break;
					case '9':a[9]++; if (a[9] == 2) return false; break;


					}
				}
			}

			for (int j = 1; j < 10; j++)
			{
				a[j] = 0;
			}
		}
	}
	return true;
}