#pragma once
/*****
�����漰����֪ʶ�㣺

string �Ļ����÷���
	1��int���ͺ�string���͵�ת�����õ�sprintf
	2��string��׼���ض����˺ܶ��������+=����һ�ַ����ӵ���ǰ֮��

�������Ľ����ͱ���
	1���������Ľ����һ�û��ȫ���ա�
	2���ݹ��˼�����������

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

