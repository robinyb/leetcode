class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		if (NULL == A || 0 >= n)
			return -1;

		int iBeg(0), iEnd(n-1), iMid(0);
		while (iBeg <= iEnd) {
			iMid = iBeg + (iEnd-iBeg)/2;
			if (target == A[iMid])
				break;
			if (target < A[iMid])
				iEnd = iMid - 1;
			else
				iBeg = ++iMid;
		}

		return iMid;
	}
};
