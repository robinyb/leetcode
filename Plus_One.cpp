class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		int iTail(digits.size()-1);
		if (0 > iTail)
			return digits;

		for (; 0 <= iTail; --iTail) {
			if (9 != digits[iTail]) {
				++digits[iTail];

				return digits;
			}

			digits[iTail] = 0;
		}

		if (0 > iTail) {
			digits.resize(digits.size()+1);
			digits[0] = 1;
		}

		return digits;
	}
};
