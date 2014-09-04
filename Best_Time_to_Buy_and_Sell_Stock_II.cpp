class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (1 >= prices.size())
			return 0;

		int iRet(0);
		for (int i(1); i < prices.size(); ++i)
			if (prices[i] > prices[i-1])
				iRet += prices[i] - prices[i-1];

		return iRet;
	}
};
