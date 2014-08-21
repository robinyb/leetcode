class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		if (NULL == A || 0 >= n)
			return 0;

		int iR(-1);
		for (int i(0); i < n; ++i)
			if (A[i] != elem)
				A[++iR] = A[i];

		return iR+1;
	}
};
