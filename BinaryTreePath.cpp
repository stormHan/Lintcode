#include "BinaryTreePath.h"

void BinaryTreePath::test(void)
{
	/*------------二叉树的建立还需要练习-------------*/
	vector<string> s;
	TreeNode root1(1);
	//root1->val = 1;
	
	TreeNode root2(2);
	//root2->val = 2;

	TreeNode root3(3);
	//root3->val = 3;

	TreeNode root4(5);
	//root4->val = 5;

	root1.left = &root2;
	root1.right = &root3;

	root2.left = &root4;

	s = binaryTreePaths(&root1);

	for (vector<string>::iterator iter = s.begin(); iter < s.end(); iter++)
	{
		cout << *iter << endl;
	}
}

vector<string>BinaryTreePath::binaryTreePaths(TreeNode *root)
{
	vector<string> l_result, r_result,result;
	bool lflag = false, rflag = false;
	if (root == NULL) return result;


	char t[256];
	sprintf(t, "%d", root->val);

	
		if (root->left != NULL)
		{
			lflag = true;
			l_result = binaryTreePaths(root->left);
		}

		if (root->right != NULL)
		{
			rflag = true;
			r_result = binaryTreePaths(root->right);
		}
	
	if (lflag)
	{
		for (vector<string>::iterator iter = l_result.begin(); iter < l_result.end(); iter++)
		{	
			string temp;
			temp = t;
			temp += '-';
			temp += '>';
			temp += *iter;
			result.push_back(temp);
		}
	}

	if (rflag)
	{
		for (vector<string>::iterator iter = r_result.begin(); iter < r_result.end(); iter++)
		{
			string temp;
			temp = t;
			temp += '-';
			temp += '>';
			temp += *iter;
			result.push_back(temp);
		}
	}

	if (!lflag && !rflag)
	{
		string temp;
		temp = t;
		result.push_back(temp);
	}
	return result;

}