class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		string sAns;
		helper(s, 0, sAns, 4);

		return m_vRet;
	}

private:
	void helper(const string& s, int iStart, string& sAns, int iLevel) {
		if (0 == iLevel) {
			if (iStart == s.size())
				m_vRet.push_back(sAns);
			return;
		}

		int iNumLeft(s.size()-iStart);
		if (iNumLeft < iLevel || iNumLeft > 3 * iLevel)
			return;

		string sTmp;
		for (int i(0); i < 3 && iStart+i < s.size(); ++i) {
			sTmp += s[iStart+i];
			if (!isLegal(sTmp))
				break;
			if (1 < iLevel)
				sTmp += '.';
			sAns += sTmp;
			helper(s, iStart+i+1, sAns, iLevel-1);
			sAns.resize(sAns.size()-sTmp.size());
			if (0 == i && '0' == s[iStart])
				break;
			if (1 < iLevel)
				sTmp.resize(sTmp.size()-1);
		}
	}

	bool isLegal(const string& s) {
		int iNum(0);
		for (int i(0); i < s.size(); ++i)
			iNum = iNum * 10 + s[i] - '0';

		if (0 <= iNum && 255 >= iNum)
			return true;

		return false;
	}

private:
	vector<string> m_vRet;
};
