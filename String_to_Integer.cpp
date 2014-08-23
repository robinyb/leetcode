class Solution {
public:
	int atoi(const char *str) {
		if (NULL == str)
			return 0;

		bool bNeg(false), bOverflow(false), bStart(false);
		long long iR(0);

		while ('\0' != *str) {
			if (bStart || ('0' <= *str && '9' >= *str))
				break;
			if ('-' == *str) {
				bNeg = true;
				bStart = true;
			} else if ('+' == *str)
				bStart = true;
			else if (' ' != *str)
				break;

			++str;
		}

		while ('\0' != *str) {
			if (!('0' <= *str && '9' >= *str))
				break;

			iR = iR * 10 + (*str - '0');
			if (INT_MAX < iR) {
				bOverflow = true;
				break;
			}

			++str;
		}

		if (bOverflow)
			return (bNeg? INT_MIN: INT_MAX);

		return (bNeg? -iR: iR);
	}
};
