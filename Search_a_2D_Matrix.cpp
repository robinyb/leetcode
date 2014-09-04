class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int iRow(matrix.size());
		if (0 == iRow)
			return false;
		int iCol(matrix[0].size());

		int iBeg(0), iEnd(iRow-1);
		while (iBeg < iEnd) {
			int iMid = iBeg + (iEnd-iBeg)/2 + 1;
			if (target == matrix[iMid][0])
				return true;
			if (target < matrix[iMid][0])
				iEnd = iMid - 1;
			else
				iBeg = iMid;
		}

		iRow = iEnd;
		iBeg = 0, iEnd = iCol - 1;

		while (iBeg <= iEnd) {
			int iMid = iBeg + (iEnd-iBeg)/2;
			if (target == matrix[iRow][iMid])
				return true;
			else if (target < matrix[iRow][iMid])
				iEnd = iMid - 1;
			else 
				iBeg = iMid + 1;
		}

		return false;
	}
};
