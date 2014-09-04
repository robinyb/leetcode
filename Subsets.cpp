class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		vector<int> vTmp;
		vRet.push_back(vTmp);

		sort(S.begin(), S.end());
		helper(S, 0, vTmp);

		return vRet;
	}

private:
	void helper(vector<int>& vS, int iBeg, vector<int>& vTmp) {

		for (int i(iBeg); i < vS.size(); ++i) {
			vTmp.push_back(vS[i]);
			vRet.push_back(vTmp);

			if (i+1 < vS.size()) {
				helper(vS, i+1, vTmp);
			}

			vTmp.pop_back();
		}
	}

private:
	vector<vector<int> > vRet;
};
