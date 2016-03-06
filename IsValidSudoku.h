#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class IsValidSudoku
{
public:
	void test(void);

	bool isValidSudoku(const vector<vector<char>> &board);
};

