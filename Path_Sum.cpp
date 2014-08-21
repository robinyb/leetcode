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
	bool hasPathSum(TreeNode *root, int sum) {
		if (NULL == root)
			return false;

		sum -= root->val;
		if (NULL == root->left && NULL == root->right)
			if (0 == sum)
				return true;
			else
				return false;

		if (hasPathSum(root->left, sum) || hasPathSum(root->right, sum))
			return true;

		return false;
	}
};
