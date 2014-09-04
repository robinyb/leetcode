class Solution {
public:
	int maxArea(vector<int> &height) {
		int iRet(0), iLeft(0), iRight(height.size()-1);
		while (iLeft < iRight) {
			int iTmp = min(height[iLeft], height[iRight]) * (iRight - iLeft);
			if (iTmp > iRet)
				iRet = iTmp;

			if (height[iLeft] > height[iRight])
				--iRight;
			else
				++iLeft;
		}

		return iRet;
	}
};
