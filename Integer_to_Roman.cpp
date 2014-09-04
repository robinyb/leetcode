class Solution {
public:
	string intToRoman(int num) {
		int val[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
		string r[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
		int i(0);
		string sR("");

		while (num) {
			while (num >= val[i]) {
				sR += r[i];
				num -= val[i];
			}

			++i;
		}

		return sR;
	}
};
