class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int iRow(obstacleGrid.size());
		if (0 == iRow)
			return 0;
		int iCol(obstacleGrid[0].size());
		vector<vector<int> > dp(iRow, vector<int>(iCol, 0));

		dp[0][0] = (1 == obstacleGrid[0][0]? 0: 1);
		for (int i(1); i < iRow; ++i)
			dp[i][0] = (1 == obstacleGrid[i][0])? 0: dp[i-1][0];
		for (int j(1); j < iCol; ++j)
			dp[0][j] = (1 == obstacleGrid[0][j])? 0: dp[0][j-1];

		for (int m(1); m < iRow; ++m)
			for (int n(1); n < iCol; ++n) {
				if (1 == obstacleGrid[m][n])
					dp[m][n] = 0;
				else
					dp[m][n] = dp[m-1][n] + dp[m][n-1];
			}

		return dp[iRow-1][iCol-1];
	}
};
