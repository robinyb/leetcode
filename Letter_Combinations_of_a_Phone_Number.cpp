class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> vRet;
		string sTmp("");
		helper(digits, 0, sTmp, vRet);

		return vRet;
	}

private:
	void helper(const string& dig, int iNum, string& s, vector<string>& ret) {
		if (iNum == dig.size()) {
			ret.push_back(s);
			return;
		}

		int iDig = dig[iNum] - '0';
		for (auto c: mp[iDig]) {
			s += c;
			helper(dig, iNum+1, s, ret);
			s.resize(s.size()-1);
		}
	}

private:
	string mp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};
