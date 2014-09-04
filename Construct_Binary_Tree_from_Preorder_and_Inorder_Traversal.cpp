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
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
	}

private:
	TreeNode *helper(vector<int> &preorder, int iPreBeg, int iPreEnd, vector<int> &inorder, int iInBeg, int iInEnd) {
		if (iPreEnd - iPreBeg != iInEnd - iInBeg || iPreBeg > iPreEnd || iInBeg > iInEnd)
			return NULL;
		TreeNode *newRoot = new TreeNode(preorder[iPreBeg]);
		if (iPreBeg == iPreEnd)
			return newRoot;

		int iTmp(iInBeg);
		for (; iTmp <= iInEnd; ++iTmp)
			if (inorder[iTmp] == preorder[iPreBeg])
				break;

		newRoot->left = helper(preorder, iPreBeg+1, iPreBeg+iTmp-iInBeg, inorder, iInBeg, iTmp-1);
		newRoot->right = helper(preorder, iPreBeg+iTmp-iInBeg+1, iPreEnd, inorder, iTmp+1, iInEnd);

		return newRoot;
	}
};
