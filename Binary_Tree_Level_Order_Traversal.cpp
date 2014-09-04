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
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > vRet;
		if (NULL == root)
			return vRet;
		queue<TreeNode *> Q;
		Q.push(root);
		int iNum(1), iNxtNum;

		while (!Q.empty()) {
			vector<int> vTmp;
			iNxtNum = 0;

			while (iNum--) {
				TreeNode *pNode = Q.front();
				Q.pop();
				if (pNode->left) {
					Q.push(pNode->left);
					++iNxtNum;
				}
				if (pNode->right) {
					Q.push(pNode->right);
					++iNxtNum;
				}
				vTmp.push_back(pNode->val);
			}

			vRet.push_back(vTmp);
			iNum = iNxtNum;
		}
	}
};
