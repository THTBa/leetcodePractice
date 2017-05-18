#include <iostream> 
#include <string>
using namespace std;

class Solution {
public:
	static string getPermutation(int n, int k) {
		string res;
		int fac_n = 1;
		if (n > 9) return "";
		string num;
		for (int i = 1; i <= n; ++i) {
			num.push_back(i + '0');
			fac_n *= i;
		}
		if (k > fac_n)return "";

		for (int i = 0; i < n; ++i) {
			fac_n /= n - i;
			int l = k / fac_n;
			if (k == l * fac_n)--l;
			res.push_back(num[l]);
			num.erase(num.begin() + l);
			if (l)k %= l * fac_n;
		}
		return res;
	}
};

int main() {
	cout << Solution::getPermutation(2, 1);
	getchar();
}