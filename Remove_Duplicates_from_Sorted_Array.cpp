class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (NULL == A || 0 >= n)
			return 0;

		int i(0), j(1);
		while (j < n) {
			if (A[i] != A[j])
				A[++i] = A[j];
			++j;
		}

		return i+1;
	}
};
