class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		if (4 > num.size())
			return m_Ret;

		sort(num.begin(), num.end());
		vector<int> vTmp;
		kSum(4, num, 0, target, vTmp);

		return m_Ret;
	}

private:
	void kSum(int k, vector<int>& num, int iBeg, int target, vector<int>& vAns) {
		if (2 < k) {
			int i(iBeg);
			while (i <= num.size()-k) {
				vAns.push_back(num[i]);
				kSum(k-1, num, i+1, target, vAns);
				vAns.pop_back();

				++i;
				while (num[i] == num[i-1] && i < num.size())
					++i;
			}

			return;
		}

		int iTmp(0);
		for (int iPre: vAns)
			iTmp += iPre;
		int iStart(iBeg), iEnd(num.size()-1);

		while (iStart < iEnd) {
			int iSum(iTmp + num[iStart] + num[iEnd]);
			if (iSum == target) {
				vAns.push_back(num[iStart]);
				vAns.push_back(num[iEnd]);
				m_Ret.push_back(vAns);
				vAns.pop_back();
				vAns.pop_back();
				++iStart;
				--iEnd;
			} else if (iSum < target)
				++iStart;
			else
				--iEnd;

			while (iBeg != iStart && num[iStart] == num[iStart-1] && iStart < iEnd)
				++iStart;
		}
	}

private:
	vector<vector<int> > m_Ret;
};
