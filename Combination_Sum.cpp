class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<int> m_vTmp;
		sort(candidates.begin(), candidates.end());
		helper(candidates, target, 0, m_vTmp);

		return m_vRet;
	}

private:
	void helper(vector<int>& vCandi, int iTar, int iPos, vector<int>& vTmp) {
		if (0 == iTar) {
			m_vRet.push_back(vTmp);
			return;
		}

		for (int i(iPos); i < vCandi.size(); ++i) {
			if (vCandi[i] <= iTar) {
				vTmp.push_back(vCandi[i]);
				helper(vCandi, iTar-vCandi[i], i, vTmp);
				vTmp.pop_back();
			} else
				break;
		}
	}

private:
	vector<vector<int> > m_vRet;
};
