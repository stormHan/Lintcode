#include "LongestIncreasingContinuousSubsequence.h"

void LongestIncreasingContinuousSubsequence::test()
{
	vector<int> v;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	/*
	for (vector<int> :: iterator iter = v.begin(); iter < v.end(); ++iter)
	{
		cout << *iter << endl;
	}*/

	int result = longestIncreasingContinuousSub(v);

	cout << result;
}

int LongestIncreasingContinuousSubsequence::longestIncreasingContinuousSub(vector<int> A)
{
	int count = 1,count_temp = 1;
	bool flag = true;
	if (A.size() == 0) return 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (i + 1 == A.size()) break;
		if (flag)
		{
			if (A[i] < A[i + 1])
			{
				count_temp++;
			}
			else if (A[i] == A[i + 1])
			{
				count_temp = 1;
			}
			else
			{
				count_temp = 2;
				flag = !flag;
			}
		}
		else 
		{
			if (A[i] > A[i + 1])
			{
				count_temp++;
			}
			else if (A[i] == A[i + 1])
			{
				count_temp = 1;
			}
			else
			{
				count_temp = 2;
				flag = !flag;
			}
		}

		if (count_temp > count)
			count = count_temp;
	}

	return count;
}
