class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		int iRow(matrix.size());
		if (0 == iRow)
			return;
		int iCol(matrix[0].size());
		bool bRow(false), bCol(false);

		/* record state of row 0 & col 0 */
		for (int i(0); i < iRow; ++i)
			if (0 == matrix[i][0]) {
				bCol = true;
				break;
			}
		for (int j(0); j < iCol; ++j)
			if (0 == matrix[0][j]) {
				bRow = true;
				break;
			}

		/* record state of maxtrix in row 0 & col 0 */
		for (int m(1); m < iRow; ++m)
			for (int n(1); n < iCol; ++n)
				if (0 == matrix[m][n]) {
					matrix[0][n] = 0;
					matrix[m][0] = 0;
				}

		/* update state of maxtrix */
		for (int i(1); i < iRow; ++i)
			if (0 == matrix[i][0])
				for (int j(0); j < iCol; ++j)
					matrix[i][j] = 0;
		for (int i(1); i < iCol; ++i)
			if (0 == matrix[0][i])
				for (int j(0); j < iRow; ++j)
					matrix[j][i] = 0;

		/* update state of row 0 & col 0 */
		if (bRow)
			for (int m(0); m < iCol; ++m)
				matrix[0][m] = 0;
		if (bCol)
			for (int n(0); n < iRow; ++n)
				matrix[n][0] = 0;
	}
};
