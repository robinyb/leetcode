class Solution {
public:
	/* description of this problem is not clear enough */
	string convert(string s, int nRows) {
		if (2 > nRows)
			return s;

		string sRet("");
		int iGap(2 * nRows - 2);
		for (int i(0); i < nRows; ++i) {
			for (int j(i); j < s.size(); j += iGap) {
				sRet += s[j];

				int iMid = j + (iGap - i * 2);
				if (0 != i && nRows-1 != i && iMid < s.size())
					sRet += s[iMid];
			}
		}

		return sRet;
	}
};
