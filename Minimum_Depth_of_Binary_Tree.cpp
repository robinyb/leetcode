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
	int minDepth(TreeNode *root) {
		if (NULL == root)
			return 0;
		if (NULL == root->left && NULL == root->right)
			return 1;

		int ld(0x7fffffff), rd(0x7fffffff);
		if (root->left) ld = minDepth(root->left);
		if (root->right) rd = minDepth(root->right);

		return ((ld < rd? ld: rd) + 1);
	}
};
