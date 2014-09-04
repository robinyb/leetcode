class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (2 > s.size())
			return s.size();

		bool szFlag[256];
		memset(szFlag, false, sizeof(szFlag));
		int iRet(1);
		int iBeg(0), iEnd(1);
		szFlag[s[iBeg]] = true;

		while (iEnd < s.size()) {
			while (szFlag[s[iEnd]]) {
				szFlag[s[iBeg++]] = false;
			}

			if (iRet < iEnd - iBeg + 1)
				iRet = iEnd - iBeg + 1;

			szFlag[s[iEnd]] = true;
			++iEnd;
		}

		return iRet;
	}
};
