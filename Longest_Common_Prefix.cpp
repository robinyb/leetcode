class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		int iStrNum(strs.size());
		if (0 == iStrNum)
			return string("");
		if (1 == iStrNum)
			return strs[0];

		string sR("");
		for (int i(0); i < strs[0].size(); ++i) {
			int j(1);
			for (; j < iStrNum; ++j) {
				if (strs[j].size() <= i || strs[j][i] != strs[0][i])
					break;
			}

			if (j < iStrNum)
				break;
			sR += strs[0][i];
		}

		return sR;
	}
};
