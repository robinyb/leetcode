/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 * int val;
 * TreeLinkNode *left, *right, *next;
 * TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root || !root->left)
			return;

		root->left->next = root->right;
		root->right->next = (NULL == root->next)? NULL: root->next->left;

		connect(root->left);
		connect(root->right);
	}
};
