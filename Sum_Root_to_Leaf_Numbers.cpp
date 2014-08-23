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
	int sumNumbers(TreeNode *root) {
		if (NULL == root)
			return 0;

		int iTmp(0);
		helper(root, iTmp);

		return m_iSum;
	}

private:
	void helper(TreeNode* root, int iTmp) {
		iTmp = iTmp * 10 + root->val;
		if (NULL == root->left && NULL == root->right) {
			m_iSum += iTmp;
			return;
		}

		if (root->left)
			helper(root->left, iTmp);
		if (root->right)
			helper(root->right, iTmp);
	}

private:
	int m_iSum;
};
