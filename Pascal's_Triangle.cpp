class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > vRet;
		if (0 == numRows)
			return vRet;

		vRet.push_back(vector<int>(1, 1));
		for (int i(1); i < numRows; ++i) {
			vector<int> vRow;
			vRow.push_back(1);
			vector<int>& vPre = vRet[i-1];

			for (int j(1); j < vPre.size(); ++j)
				vRow.push_back(vPre[j-1] + vPre[j]);

			vRow.push_back(1);
			vRet.push_back(vRow);
		}

		return vRet;
	}
};
