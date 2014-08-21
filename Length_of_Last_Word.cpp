class Solution {
public:
	int lengthOfLastWord(const char *s) {
		if (NULL ==s)
			return 0;

		int iR(0);
		while ('\0' != *s) {
			if (' ' != *s) {
				iR = 0;
				for (; '\0' != *s && ' ' != *s; ++s)
					++iR;
			} else
				++s;
		}

		return iR;
	}
};
