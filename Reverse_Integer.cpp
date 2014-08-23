class Solution {
public:
	int reverse(int x) {
		int iR(0);

		/* same with negtive integer */
		while (x) {
			iR = iR * 10 + (x % 10);
			x /= 10;
		}

		return iR;
	}
};
