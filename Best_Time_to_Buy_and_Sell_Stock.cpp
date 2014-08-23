class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (0 == prices.size())
			return 0;
		int iRet(0), iLow(prices[0]);
		for (int i(1); i < prices.size(); ++i) {
			iLow = min(iLow, prices[i]);
			iRet = max(iRet, prices[i] - iLow);
		}

		return iRet;
	}
};
