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
	void flatten(TreeNode *root) {
		if (NULL == root)
			return;
		TreeNode *pL = root->left;
		TreeNode *pR = root->right;
		flatten(pL);
		flatten(pR);

		root->left = NULL;
		root->right = pL;
		TreeNode *pT = root;
		while (pT->right)
			pT = pT->right;
		pT->right = pR;
	}
};
