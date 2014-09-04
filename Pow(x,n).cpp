class Solution {
public:
	double pow(double x, int n) {
		if (isZero(x) && 0 == n)
			return -1;
		if (isZero(x))
			return 0;
		if (0 == n)
			return 1;

		bool bNeg(false);
		if (n < 0) {
			n = -n;
			bNeg = true;
		}

		double ret = 1;
		while (n) {
			if (n&1)
				ret *= x;
			n /= 2;
			x *= x;
		}

		return bNeg? 1/ret: ret;
	}

private:
	bool isZero(double x) {
		if (abs(x) < 1e-9)
			return true;
		return false;
	}
};
