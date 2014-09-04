class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		if (3 > num.size())
			return target;
		sort(num.begin(), num.end());

		/* init of iRet & iMin(below) can't be 0x7fffffff, avoid abs overflow */
		int iRet(999999), i(0);
		while (i < num.size() - 2) {
			int iTmp = twoSumClosest(num, i, target);
			if (abs(iTmp, target) < abs(iRet, target))
				iRet = iTmp;

			++i;
			while (num[i] == num[i-1] && i < num.size())
				++i;
		}

		return iRet;
	}

private:
	int twoSumClosest(vector<int>& num, int iElem, int target) {
		int iTar = target - num[iElem];
		int iBeg(iElem+1), iEnd(num.size()-1), iMin(999999);

		while (iBeg < iEnd) {
			if (abs(num[iBeg]+num[iEnd], iTar) < abs(iMin, iTar))
				iMin = num[iBeg]+num[iEnd];
			if (iTar < num[iBeg] + num[iEnd])
				--iEnd;
			else
				++iBeg;

			while (iElem+1 != iBeg && num[iBeg] == num[iBeg-1] && iBeg < num.size())
				++iBeg;
		}

		return iMin+num[iElem];
	}

	int abs(int a, int b) {
		if (a < b)
			return b - a;
		return a - b;
	}
};
