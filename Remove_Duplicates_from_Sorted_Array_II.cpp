class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (NULL == A || 2 >= n)
			return n;

		int iPos(0), iJudge(A[0]);
		bool bExist(false);
		for (int i(1); i < n; ++i) {
			if (iJudge == A[i] && bExist)
				continue;

			A[++iPos] = A[i];
			if (iJudge == A[i])
				bExist = true;
			else {
				bExist = false;
				iJudge = A[i];
			}
		}

		return iPos+1;
	}
};
