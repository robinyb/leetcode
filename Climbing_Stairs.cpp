class Solution {
public:
	int climbStairs(int n) {
		if (0 >= n)
			return 0;
		if (2 >= n)
			return n;

		int iFirst(1), iSecond(2), iRet(0);
		for (int i(3); i <= n; ++i) {
			iRet = iFirst + iSecond;
			iFirst = iSecond;
			iSecond = iRet;
		}

		return iRet;
	}
};
