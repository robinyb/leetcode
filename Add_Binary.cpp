class Solution {
public:
	string addBinary(string a, string b) {
		string sShort, sLong;
		if (a.size() < b.size()) {
			sShort = a;
			sLong = b;
		} else {
			sShort = b;
			sLong = a;
		}
		string sRet(sLong.size()+1, '0');

		bool bCarry(false);
		int iShort(sShort.size()-1), iLong(sLong.size()-1), iRet(sRet.size()-1);
		for (; 0 <= iShort; --iShort, --iLong, --iRet) {
			if (bCarry) {
				if ('1' == sShort[iShort] && '1' == sLong[iLong]) {
					bCarry = true;
					sRet[iRet] = '1';
				} else if ('1' == sShort[iShort] || '1' == sLong[iLong]) {
					bCarry = true;
					sRet[iRet] = '0';
				} else {
					bCarry = false;
					sRet[iRet] = '1';
				}
			} else {
				if ('1' == sShort[iShort] && '1' == sLong[iLong]) {
					bCarry = true;
					sRet[iRet] = '0';
				} else if ('1' == sShort[iShort] || '1' == sLong[iLong]) {
					bCarry = false;
					sRet[iRet] = '1';
				} else {
					bCarry = false;
					sRet[iRet] = '0';
				}
			}
		}

		for (; 0 <= iLong; --iLong, --iRet) {
			if (bCarry) {
				if ('0' == sLong[iLong]) {
					sRet[iRet] = '1';
					bCarry = false;
				} else {
					sRet[iRet] = '0';
					bCarry = true;
				}
			} else
				sRet[iRet] = sLong[iLong];
		}

		if (bCarry) {
			sRet[0] = '1';
			return sRet;
		}

		return sRet.substr(1);
	}
};
