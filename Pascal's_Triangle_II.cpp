class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> vRet(rowIndex+1, 0);
		vRet[0] = 1;
		for (int i(1); i <= rowIndex; ++i)
			for (int j(i); 0 < j; --j)
				vRet[j] += vRet[j-1];

		return vRet;
	}
};
