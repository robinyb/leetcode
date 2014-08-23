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
	TreeNode *sortedArrayToBST(vector<int> &num) {
		if (0 >= num.size())
			return NULL;

		return helper(num, 0, num.size()-1);
	}
private:
	TreeNode *helper(vector<int>& A, int iBeg, int iEnd) {
		if (iBeg > iEnd)
			return NULL;

		int iMid(iBeg+(iEnd-iBeg)/2);
		TreeNode *newNode = new TreeNode(A[iMid]);
		newNode->left = helper(A, iBeg, iMid-1);
		newNode->right = helper(A, iMid+1, iEnd);

		return newNode;
	}
};
