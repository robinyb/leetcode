class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> result(26);
        for (size_t i(0); i < s.size(); ++i) {
            ++result[s[i] - 'a'];
            --result[t[i] - 'a'];
        }
        for (int j(0); j < 26; ++j) {
            if (result[j] != 0) return false;
        }
        return true;
    }
};
