class Solution {
public:
	bool isPalindrome(string s) {
		int iBeg(0), iEnd(s.size()-1);
		while (iBeg < iEnd) {
			while (iBeg < iEnd && !isAlphanumeric(s[iBeg]))
				++iBeg;
			while (iBeg < iEnd && !isAlphanumeric(s[iEnd]))
				--iEnd;

			if (iBeg < iEnd && s[iBeg] != s[iEnd])
				return false;

			++iBeg;
			--iEnd;
		}

		return true;
	}

private:
	bool isAlphanumeric(char& c) {
		if ('0' <= c && '9' >= c)
			return true;
		if ('a' <= c && 'z' >= c)
			return true;
		if ('A' <= c && 'Z' >= c) {
			c += 32;
			return true;
		}

		return false;
	}
};
