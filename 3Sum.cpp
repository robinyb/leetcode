class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > ret;
		if (3 > num.size())
			return ret;
		sort(num.begin(), num.end());

		int i(0);
		while (i < num.size() - 3) {
			int iTar(0-num[i]);
			twoSum(num, i, iTar, ret);

			++i;
			while (i < num.size() && num[i] == num[i-1])
				++i;
		}

		return ret;
	}

private:
	void twoSum(vector<int>& num, int iElem, int iTar, vector<vector<int> >& vA) {
		int i(iElem+1), j(num.size()-1);
		while (i < j) {
			int iTmp(num[i] + num[j]);
			if (iTmp == iTar) {
				vector<int> vTmp;
				vTmp.push_back(num[iElem]);
				vTmp.push_back(num[i]);
				vTmp.push_back(num[j]);
				vA.push_back(vTmp);
				++i;
				--j;
			} else if (iTmp < iTar)
				++i;
			else
				--j;

			while (iElem + 1 != i && i < num.size() && num[i] == num[i-1])
				++i;
		}
	}
};
