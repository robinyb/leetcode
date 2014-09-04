class Solution {
public:
	/* DP, bottom up */
	int minimumTotal(vector<vector<int> > &triangle) {
		int iLen(triangle.size());
		if (0 == iLen)
			return 0;

		vector<int> dp;
		for (auto elem: triangle[iLen-1])
			dp.push_back(elem);

		for (int i(iLen-2); 0 <= i; --i) {
			for (int j(0); j <= i; ++j)
				dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
		}

		return dp[0];
	}
};
