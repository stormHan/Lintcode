#pragma once
/*****
本题涉及到的知识点：

string 的基本用法，
	1）int类型和string类型的转换，用到sprintf
	2）string标准库重定义了很多操作符，+=将另一字符串加到当前之后

二叉树的建立和遍历
	1）二叉树的建立我还没完全掌握。
	2）递归的思想遍历二叉树

*/

#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class  TreeNode
{
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
	TreeNode();
};

	class BinaryTreePath
	{
	public:
		void test(void);
		vector<string> binaryTreePaths(TreeNode* root);
	};

