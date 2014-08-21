class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		queue<string> qCandi;
		queue<int> qNum;
		unordered_set<string> setTried;

		qCandi.push(start);
		qNum.push(1);
		setTried.insert(start);

		while (!qCandi.empty()) {
			string sCandi = qCandi.front();
			qCandi.pop();
			int iLen = qNum.front();
			qNum.pop();

			if (sCandi == end)
				return iLen;

			for (int i(0); i < sCandi.size(); ++i) {
				char c;
				for (c = 'a'; c <= 'z'; ++c) {
					if (c == sCandi[i])
						continue;

					char tmp = sCandi[i];
					sCandi[i] = c;
					if (dict.count(sCandi) && !setTried.count(sCandi)) {
						setTried.insert(sCandi);
						qCandi.push(sCandi);
						qNum.push(iLen+1);
					}
					sCandi[i] = tmp;
				}
			}
		}

		return 0;
	}
};
