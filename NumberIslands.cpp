#include "NumberIslands.h"


void NumberIslands::test(void)
{
	vector<vector<bool> >boo;
	ifstream fin("E://Algorithms//Lintcode//Lintcode//fileinput//numIslands.txt");

	for (int i = 0; i < 1; i++)
	{
		vector<bool> a;
		a.clear();
		for (int j = 0; j < 2; j++)
		{
			bool c;
			fin >> c;
			a.push_back(c);
		}
		boo.push_back(a);
	}
	
	//for (int i = 0; i < boo[0].size(); i++)
	//{
	//for (int j = 0; j < boo.size(); j++)
	//{
	//	cout << boo[i][j];
	//}
	//cout << endl;
	//}

	int result = numIslands(boo);
	cout << result << endl;
}

bool JudgeNewIsland(vector<vector<bool> >& grid, vector<vector<bool> >& flag, int i, int j)
{
	if (i != 0)
	{
		if (flag[i - 1][j] == true)
			return false;
	}
	if (j != 0)
	{
		if (flag[i][j - 1] == true)
			return false;
	}
	if (i != grid.size() - 1)
	{
		if (flag[i + 1][j] == true)
			return false;
	}
	if (j != grid[0].size() - 1)
	{
		if (flag[i][j + 1] == true)
			return false;
	}

	return true;
}

void Sign(vector<vector<bool> >& grid, vector<vector<bool> >& flag, int i, int j)
{
	flag[i][j] = true;
	
	if (i != 0)
	{
		if (flag[i - 1][j] == false && grid[i - 1][j] == true)
			Sign(grid, flag, i - 1, j);
	}
	if (j != 0)
	{
		if (flag[i][j - 1] == false && grid[i][j - 1] == true)
			Sign(grid, flag, i, j - 1);
	}
	if (i != grid.size() - 1)
	{
		if (flag[i + 1][j] == false && grid[i + 1][j] == true)
			Sign(grid, flag, i + 1, j);
	}
	if (j != grid[0].size() - 1)
	{
		if (flag[i][j + 1] == false && grid[i][j + 1] == true)
			Sign(grid, flag, i, j + 1);
	}
}

int NumberIslands::numIslands(vector<vector<bool> >& grid)
{
	vector<vector<bool> > flag;
	int count = 0;

	for (int i = 0; i < grid.size(); i++)
	{
		vector<bool> a;
		a.clear();
		for (int j = 0; j < grid[0].size(); j++)
		{
			bool c = false;
			a.push_back(c);
		}
		flag.push_back(a);
	}

	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[0].size(); j++)
		{
			if (grid[i][j])
			{
				bool b = JudgeNewIsland(grid, flag, i, j);
				if (b)
				{
					count++;
					Sign(grid, flag, i, j);
				}
			}
		}
	}
	return count;
}