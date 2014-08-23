class Solution {
public:
	/* description not clearly enough, not a good question, I think */
	bool isNumber(const char *s) {
		if (NULL == s)
			return false;

		while (' ' == *s)
			++s;
		if ('+' == *s || '-' == *s)
			++s;

		if ('\0' == *s)
			return false;

		bool dotFound(false), eFound(false), numFound(false);

		while ('\0' != *s) {
			if (!('0' <= *s && '9' >= *s)) {
				if (' ' == *s) {
					while ('\0' != *s)
						if (' ' != *s++)
							return false;
					return true;
				}

				if ('.' == *s) {
					if (dotFound || eFound || !(numFound || ('0' <= *(s+1) && '9' >= *(s+1))))
						return false;
					dotFound = true;
				} else if('e' == *s || 'E' == *s) {
					if ('+' == *(s+1) || '-' == *(s+1))
						++s;
					if (eFound || !numFound || !('0' <= *(s+1) && '9' >= *(s+1)))
						return false;

					eFound = true;
				} else
					return false;
			}

			numFound = true;
			++s;
		}

		return true;
	}
};
