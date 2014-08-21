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
	bool isSymmetric(TreeNode *root) {
		if (NULL == root)
			return true;

		return judge(root->left, root->right);
	}

private:
	bool judge(TreeNode* l, TreeNode* r) {
		if (NULL == l && NULL == r)
			return true;
		if (NULL == l || NULL == r)
			return false;
		if (l->val != r->val)
			return false;

		return judge(l->left, r->right) && judge(l->right, r->left);
	}
};
