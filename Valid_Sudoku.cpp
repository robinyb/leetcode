class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		bool rCheck[9][10], cCheck[9][10], subCheck[9][10];
		memset(rCheck, false, sizeof(rCheck));
		memset(cCheck, false, sizeof(cCheck));
		memset(subCheck, false, sizeof(subCheck));

		for (int i(0); i < 9; ++i) {
			for (int j(0); j < 9; ++j) {
				if ('.' != board[i][j]) {
					if (rCheck[i][board[i][j]-'0'] || cCheck[j][board[i][j]-'0'] || subCheck[(i/3)*3+(j/3)][board[i][j]-'0'])
						return false;

					rCheck[i][board[i][j]-'0'] = true;
					cCheck[j][board[i][j]-'0'] = true;
					subCheck[(i/3)*3+(j/3)][board[i][j]-'0'] = true;
				}
			}
		}

		return true;
	}
};
