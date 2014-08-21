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
	bool isBalanced(TreeNode *root) {
		if (NULL == root)
			return true;

		int iTmp(0);
		return isBalanced(root, iTmp);
	}
private:
	bool isBalanced(TreeNode *root, int &iDepth) {
		iDepth = 0;
		if (NULL == root)
			return true;

		int ld(0), rd(0);
		if (isBalanced(root->left, ld) && isBalanced(root->right, rd)) {
			if (ld + 1 < rd || rd + 1 < ld)
				return false;

			iDepth = (ld < rd? rd: ld) + 1;

			return true;
		}

		return false;
	}
};
