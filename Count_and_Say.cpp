class Solution {
public:
	string countAndSay(int n) {
		string cur("1");
		if (1 >= n)
			return cur;

		for (int i(2); i <= n; ++i) {
			string nxt("");
			for (int j(0); j < cur.size(); ++j) {
				int cnt(1);
				while (j+1 < cur.size() && cur[j] == cur[j+1]) {
					++cnt;
					++j;
				}

				string tmp("");
				while (cnt) {
					tmp = static_cast<char>('0' + (cnt%10)) + tmp;
					cnt /= 10;
				}
				nxt = nxt + tmp;
				nxt = nxt + cur[j];
			}

			cur = nxt;
		}

		return cur;
	}
};
