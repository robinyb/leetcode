class Solution {
public:
	int uniquePaths(int m, int n) {
		if (1 > m || 1 > n)
			return 0;

		int small(m-1), big(n-1);
		if (small > big) 
			swap(small, big);
		if (0 == small)
			return 1;

		long long base(m+n-2), dividend(m+n-2), divisor(small);
		for (int i(small-1); 0 < i; --i) {
			dividend = dividend * (--base);
			divisor = divisor * i;
		}

		return dividend/divisor;    
	}
};
