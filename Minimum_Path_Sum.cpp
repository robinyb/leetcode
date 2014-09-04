class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		int iRow(grid.size());
		if (0 == iRow)
			return 0;
		int iCol(grid[0].size());
		vector<vector<int> > dp(iRow, vector<int>(iCol, 0));
		dp[0][0] = grid[0][0];

		for (int i(1); i < iRow; ++i)
			dp[i][0] = dp[i-1][0] + grid[i][0];
		for (int j(1); j < iCol; ++j)
			dp[0][j] = dp[0][j-1] + grid[0][j];

		for (int m(1); m < iRow; ++m)
			for (int n(1); n < iCol; ++n)
				dp[m][n] = grid[m][n] + min(dp[m-1][n], dp[m][n-1]);

		return dp[iRow-1][iCol-1];
	}
};
