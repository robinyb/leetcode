class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		vector<string> ans;
		map<string, vector<string> > hmp;

		for (auto s: strs) {
			string tmps = s;
			sort(tmps.begin(),tmps.end());
			hmp[tmps].push_back(s);
		}

		for (auto p: hmp) {
			if (p.second.size() > 1)
				for (auto s: p.second)
					ans.push_back(s);
		}

		return ans;
	}
};
