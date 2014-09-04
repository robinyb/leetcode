class Solution {
public:
	vector<vector<string>> partition(string s) {
		if (0 == s.size())
			return m_vRet;
		helper(s, 0, s.size()-1);

		return m_vRet;
	}

private:
	void helper(const string &s, int iBeg, int iEnd) {
		if (iBeg > iEnd) {
			m_vRet.push_back(m_vCandi);

			return;
		}

		for (int i(iBeg); i <= iEnd; ++i) {
			if (isPalindrome(s, iBeg, i)) {
				m_vCandi.push_back(s.substr(iBeg, i-iBeg+1));
				helper(s, i+1, iEnd);
				m_vCandi.pop_back();
			}
		}
	}

	bool isPalindrome(const string &s, int iBeg, int iEnd) {
		while (iBeg <= iEnd)
			if (s[iBeg++] != s[iEnd--])
				return false;

		return true;
	}

private:
	vector<vector<string>> m_vRet;
	vector<string> m_vCandi;
};
