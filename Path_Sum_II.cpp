/**
 * Definition for binary tree
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		if (NULL == root)
			return m_vPath;

		vector<int> myStack;
		helper(root, sum, myStack);

		return m_vPath;
	}

private:
	void helper(TreeNode* root, int sum, vector<int>& Stack) {
		Stack.push_back(root->val);
		sum -= root->val;
		if (NULL == root->left && NULL == root->right) {
			if (0 == sum)
				m_vPath.push_back(Stack);

			Stack.pop_back();
			return;
		}

		if (root->left)
			helper(root->left, sum, Stack);
		if (root->right)
			helper(root->right, sum, Stack);

		Stack.pop_back();
	}

private:
	vector<vector<int> > m_vPath;
};
