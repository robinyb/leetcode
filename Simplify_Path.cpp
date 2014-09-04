class Solution {
public:
	/* some test cases are not legal path, bad problem */
	string simplifyPath(string path) {
		if (path.size() < 2 )
			return path;
		string sRet("");

		int iDotNum(0), iSlashNum(0);
		for (int i(0); i < path.size(); ++i) {
			if ('.' == path[i]) {
				++iDotNum;
				iSlashNum = 0;
				if (2 < iDotNum) {
					int j(i+1);
					for (; j < path.size() && path[j] == '.'; ++j)
						++iDotNum;
					i = j - 1;
					for (; iDotNum; --iDotNum)
						sRet += '.';
				}
			}
			else if ('/' == path[i]) {
				if (0 == iDotNum && 0 == iSlashNum)
					sRet += path[i];
				else if (2 == iDotNum) {
					popLastStr(sRet);
				}

				iDotNum = 0;
				++iSlashNum;
			} else {
				for (; iDotNum; --iDotNum)
					sRet += '.';
				iSlashNum = 0;
				sRet +=  path[i];
			}
		}

		if (iDotNum == 2) {
			popLastStr(sRet);
		}

		if (1 < sRet.size() && '/' == sRet[sRet.size()-1])
			sRet.resize(sRet.size()-1);

		return sRet;
	}

private:
	void popLastStr(string& sRet) {
		bool bFlag(false);
		int j(sRet.size()-1);
		for (; 0 <= j; --j) {
			if ('/' != sRet[j])
				bFlag = true;
			if (bFlag && '/' == sRet[j])
				break;
		}
		if (bFlag)
			sRet.resize(j+1);
	}
};
