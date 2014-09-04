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
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
	}

private:
	TreeNode *helper(vector<int> &in, int il, int ir, vector<int> &post, int pl, int pr) {
		if (il > ir || pl > pr)
			return NULL;

		TreeNode *newRoot = new TreeNode(post[pr]);
		int iM(il);
		while (in[iM] != post[pr])
			++iM;

		newRoot->left = helper(in, il, iM-1, post, pl, pl+iM-il-1);
		newRoot->right = helper(in, iM+1, ir, post, pl+iM-il, pr-1);

		return newRoot;
	}
};
