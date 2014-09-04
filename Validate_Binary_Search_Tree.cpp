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
	bool isValidBST(TreeNode *root) {
		int iPre(-0x7fffffff);

		return helper(root, iPre);
	}

private:
	bool helper(TreeNode *root, int &iMin) {
		if (NULL == root)
			return true;

		if (!helper(root->left, iMin))
			return false;
		if (root->val <= iMin)
			return false;
		iMin = root->val;

		return helper(root->right, iMin);
	}
};
