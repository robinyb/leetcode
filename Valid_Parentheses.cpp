class Solution {
public:
	bool isValid(string s) {
		stack<char> myS;

		for (int i(0); i < s.size(); ++i) {
			char c('x');
			switch (s[i]) {
			case ')': c = '('; break;
			case ']': c = '['; break;
			case '}': c = '{'; break;
			default: myS.push(s[i]); break;
			}

			if ('x' != c) {
				if (myS.empty() || c != myS.top())
					return false;

				myS.pop();
			}
		}

		if (myS.empty())
			return true;

		return false;
	}
};
