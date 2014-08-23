class Solution {
public:
	bool isPalindrome(int x) {
		if (0 > x)
			return false;

		int iHelper(1);
		while (10 <= x / iHelper)
			iHelper *= 10;

		while (x) {
			if (x % 10 != x / iHelper)
				return false;

			x = (x % iHelper) / 10;
			iHelper /= 100;
		}

		return true;
	}
};
