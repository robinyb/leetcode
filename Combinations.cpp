class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		if (0 >= k || k > n)
			return vRet;
		vector<int> vTmp;
		helper(1, n, k, vTmp);

		return vRet;
	}

private:
	void helper(int iBeg, int iEnd, int k, vector<int>& v) {
		if (0 == k) {
			vRet.push_back(v);
			return;
		}

		for (int i(iBeg); i <= iEnd-k+1; ++i) {
			v.push_back(i);
			helper(i+1, iEnd, k-1, v);
			v.pop_back();
		}
	}

private:
	vector<vector<int> > vRet;
};
