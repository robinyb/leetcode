class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		map<int, int> mNums;
		map<int, int>::iterator iterNums;
		const int iEnd(numbers.size());

		for (int i(0); i < iEnd; ++i) {
			iterNums = mNums.find(target-numbers[i]);

			if (mNums.end() != iterNums) {
				vector<int> vR;
				vR.push_back(iterNums->second);
				vR.push_back(i+1);

				return vR;
			}

			if (mNums.end() == mNums.find(numbers[i])) {
				mNums.insert(make_pair(numbers[i], i+1));
			}
		}
	}
};
