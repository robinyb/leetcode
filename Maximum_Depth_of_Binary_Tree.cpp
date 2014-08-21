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
	int maxDepth(TreeNode *root) {
		if (NULL == root)
			return 0;

		int ld = maxDepth(root->left);
		int rd = maxDepth(root->right);

		return ((ld < rd? rd: ld) + 1);
	}
};
