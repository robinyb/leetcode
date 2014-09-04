class Solution {
public:
	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict)
	{
		unordered_map<string, vector<string>> prevMap;

		for(auto iter = dict.begin(); iter != dict.end(); ++iter)
		{
			prevMap[*iter] = vector<string>();
		}

		vector<unordered_set<string>> vCandi(2);

		int current = 0;
		int previous = 1;

		vCandi[current].insert(start);

		while (true) {
			current = !current;
			previous = !previous;

			for (auto iter = vCandi[previous].begin(); iter != vCandi[previous].end(); ++iter)
				dict.erase(*iter);

			vCandi[current].clear();

			/* bfs & record prev node */
			for (auto iter = vCandi[previous].begin(); iter != vCandi[previous].end(); ++iter) {
				for (int pos(0); pos < iter->size(); ++pos) {
					string word = *iter;

					for (int i = 'a'; i <= 'z'; ++i) {
						if (word[pos] == i)
							continue;

						word[pos] = i;
						if (dict.count(word)) {
							prevMap[word].push_back(*iter);
							vCandi[current].insert(word);
						}
					}
				}
			}

			if (0 == vCandi[current].size())
				return m_Ret;

			if (vCandi[current].count(end))
				break;
		}


		vector<string> path;
		GeneratePath(prevMap, path, end);

		return m_Ret;
	}

private:
	/* dfs to get result */
	void GeneratePath(unordered_map<string, vector<string>> &prevMap, vector<string>& path,
			const string& word) {
		if (0 == prevMap[word].size()) {
			path.push_back(word);
			vector<string> curPath = path;
			reverse(curPath.begin(), curPath.end());
			m_Ret.push_back(curPath);
			path.pop_back();

			return;
		}

		path.push_back(word);
		for (auto iter = prevMap[word].begin(); iter != prevMap[word].end(); ++iter)
			GeneratePath(prevMap, path, *iter);

		path.pop_back();
	}

private:
	vector<vector<string>> m_Ret;
};
