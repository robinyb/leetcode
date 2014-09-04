class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> > vRet(n, vector<int>(n, 0));
		int iBeg(0), iEnd(n-1);
		int iNum(1);

		while (iBeg < iEnd) {
			for (int i(iBeg); i < iEnd; ++i)
				vRet[iBeg][i] = iNum++;

			for (int j(iBeg); j < iEnd; ++j)
				vRet[j][iEnd] = iNum++;

			for (int i(iEnd); iBeg < i; --i)
				vRet[iEnd][i] = iNum++;

			for (int j(iEnd); iBeg < j; --j)
				vRet[j][iBeg] = iNum++;

			++iBeg;
			--iEnd;
		}

		if (iBeg == iEnd)
			vRet[iBeg][iEnd] = iNum;

		return vRet;
	}
};
