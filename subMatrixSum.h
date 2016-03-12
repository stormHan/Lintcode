#include <vector>

using namespace std;

bool SumMatrix(vector<vector<int>> index, vector<vector<int>>& matrix)
{
	int sum = 0;
	if (index[0][0] == index[1][0] && index[0][1] == index[1][1])
		sum = matrix[index[0][0]][index[1][1]];

	for (int i = index[0][0]; i < index[0][1]; i++)
	{
		for (int j = index[1][0]; j < index[1][1]; j++)
		{
			sum += matrix[i][j];
		}
	}

	if (sum == 0)
		return true;
	else
	{
		return false;
	}
}

vector<vector<int>> submatrixSum(vector<vector<int>>& matrix)
{
	vector<vector<int>> index;
	vector<int> temp_vec1;
	vector<int> temp_vec2;

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{

			for (int i1 = i; i1 < matrix.size(); i1++)
			{
				for (int j1 = j; j1 < matrix[0].size(); j1++)
				{
					//while (temp_vec1.size() != 0)
					//{
					//	temp_vec1.pop_back();
					//}
					//while (temp_vec2.size() != 0)
					//{
					//	temp_vec2.pop_back();
					//}

					temp_vec1.push_back(i);
					temp_vec1.push_back(j);
					index.push_back(temp_vec1);
					
					temp_vec2.push_back(i1);
					temp_vec2.push_back(j1);
					index.push_back(temp_vec2);

					if (SumMatrix(index, matrix))
					{
						return index;
					}
					else
					{
						index.pop_back(); 
						index.pop_back();

						temp_vec1.pop_back();
						temp_vec1.pop_back();
						temp_vec2.pop_back();
						temp_vec2.pop_back();
					}
				}
			}
		}
	}
}