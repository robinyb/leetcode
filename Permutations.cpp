class Solution {
public:
	vector<vector<int> > permute(vector<int> &num) {
		vector<int> vTmp;
		helper(num, 0, vTmp);

		return m_vRet;
	}

private:
	void helper(vector<int>& num, int iPos, vector<int>& vTmp) {
		if (iPos == num.size()) {
			m_vRet.push_back(vTmp);
			return;
		}

		for (int i(iPos); i < num.size(); ++i) {
			swap(num[iPos], num[i]);
			vTmp.push_back(num[iPos]);
			helper(num, iPos+1, vTmp);
			vTmp.pop_back();
			swap(num[iPos], num[i]);
		}
	}

private:
	vector<vector<int> > m_vRet;
};
