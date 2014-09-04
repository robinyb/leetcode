class Solution {
public:
	int numDecodings(string s) {
		if (!s.size() || s[0]=='0')
			return 0;
		int cur_2 = 1,cur_1 = 1,cur = 0;

		for (int i(2); i <= s.size(); i++) {
			if (s[i-1] != '0')
				cur += cur_1;
			if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7'))
				cur += cur_2;

			cur_2 = cur_1;
			cur_1 =  cur;
			cur = 0;
		}

		return cur_1;
	}
};
