#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		vector<int> vRet;
		if (0 == L.size())
			return vRet;

		unordered_map<string, int> mp;
		unordered_map<string, int> mcur;
		for (auto s: L)
			++mp[s];
		int iWordLen(L[0].size());

		/* 
		 * attention: "i < S.size()-iWordLen*L.size() won't work normally,
		 * since the left is signed int while the right is unsigned 
		 * */
		for (int i(0); i + iWordLen*L.size() <= S.size(); ++i) {
			mcur.clear();
			int j(0);
			for (; j < L.size(); ++j) {
				string sTmp = S.substr(i + iWordLen * j, iWordLen);
				++mcur[sTmp];
				if (mp.end() == mp.find(sTmp) || mp[sTmp] < mcur[sTmp])
					break;
			}

			if (j >= L.size())
				vRet.push_back(i);
		}

		return vRet;
	}
};

int main()
{
	vector<string> v(1, "mississippis");
	Solution().findSubstring("mississippi", v);
}
