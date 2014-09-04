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
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		stack<vector<int> > S;
		queue<TreeNode *> Q;
		vector<vector<int> > R;

		if (NULL == root)
			return R;
		Q.push(root);
		int iNum(1), iNxt(0);

		while (!Q.empty()) {
			iNxt = 0;
			vector<int> vTmp;

			while (iNum--) {
				TreeNode *pNode = Q.front();
				Q.pop();
				vTmp.push_back(pNode->val);

				if (pNode->left) {
					++iNxt;
					Q.push(pNode->left);
				}
				if (pNode->right) {
					++iNxt;
					Q.push(pNode->right);
				}
			}

			iNum = iNxt;
			S.push(vTmp);
		}

		while (!S.empty()) {
			R.push_back(S.top());
			S.pop();
		}

		return R;
	}
};
