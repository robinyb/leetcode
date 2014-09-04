class Solution {
public:
	int maxSubArray(int A[], int n) {
		int iRet(-0x7fffffff);
		int iTmp(0);

		for (int i(0); i < n; ++i) {
			iTmp += A[i];
			if (iTmp > iRet)
				iRet = iTmp;
			if (0 > iTmp)
				iTmp = 0;
		}

		return iRet;
	}
};
