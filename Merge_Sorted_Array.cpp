class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		if (NULL == A || NULL == B)
			return;

		int iIndex(m+n-1);
		--m, --n;

		while (0 <= m && 0 <= n) {
			if (A[m] <= B[n]) {
				A[iIndex--] = B[n];
				--n;
			} else {
				A[iIndex--] = A[m];
				--m;
			}
		}

		while (0 <= n)
			A[iIndex--] = B[n--];
	}
};
