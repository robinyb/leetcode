class Solution {
public:
	bool exist(vector<vector<char> > &board, string word) {
		if (0 == word.size())
			return true;
		m_iRow = board.size();
		if (0 == m_iRow)
			return false;
		m_iCol = board[0].size();

		for (int i(0); i < m_iRow; ++i)
			for (int j(0); j < m_iCol; ++j) {
				if (board[i][j] == word[0]) {
					board[i][j] = '#';
					if (helper(board, word, 1, i, j))
						return true;
					board[i][j] = word[0];
				}
			}

		return false;
	}

private:
	bool helper(vector<vector<char> >& board, string& word, int iNum, int iRow, int iCol) {
		if (word.size() <= iNum)
			return true;

		for (int m(0); m < 4; ++m) {
			int iTryX = iRow + m_iDx[m];
			int iTryY = iCol + m_iDy[m];

			if (judge(iTryX, iTryY) && word[iNum] == board[iTryX][iTryY]) {
				board[iTryX][iTryY] = '#';
				if (helper(board, word, iNum+1, iTryX, iTryY))
					return true;
				board[iTryX][iTryY] = word[iNum];
			}
		}

		return false;
	}

	bool judge(int iX, int iY) {
		if (iX < 0 || iX >= m_iRow || iY < 0 || iY >= m_iCol)
			return false;
		return true;
	}

private:
	int m_iRow;
	int m_iCol;
	int m_iDx[4] = {0, 0, -1, 1};
	int m_iDy[4] = {1, -1, 0, 0};
};
