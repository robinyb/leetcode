class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (1 > n)
			return m_vRet;

		string s("");
		helper(n, s);

		return m_vRet;
	}

private:
	void helper(int n, string& s) {
		if (m_iLeft == n && m_iRight == n) {
			m_vRet.push_back(s);
			return;
		}

		if (m_iLeft < n) {
			s += "(";
			++m_iLeft;
			helper(n, s);
			s.resize(s.size()-1);
			--m_iLeft;
		}

		if (m_iRight < m_iLeft) {
			s += ")";
			++m_iRight;
			helper(n, s);
			s.resize(s.size()-1);
			--m_iRight;
		}
	}

private:
	int m_iLeft;
	int m_iRight;
	vector<string> m_vRet;
};
