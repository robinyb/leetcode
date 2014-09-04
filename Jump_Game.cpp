class Solution {
public:
	bool canJump(int A[], int n) {
		if (0 >= n)
			return true;

		int maxDis(A[0]);
		for (int i(1); i < n && maxDis >= i; ++i) {
			if (maxDis < i + A[i])
				maxDis = i + A[i];
		}

		if (maxDis >= n - 1)
			return true;

		return false;
	}
};
