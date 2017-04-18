#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	static bool isMatch(string s, string p) {
		int slength = s.length(), plength = p.length();
		vector<vector<bool>> dp(slength+1);
		for (int i = 0; i <= slength; ++i) {
			vector<bool> a(plength+1);
			dp[i] = a;
		}
		for (int i = 0; i<=slength; ++i)dp[i][0] = false;
		for (int i = 0; i <= plength; ++i)dp[0][i] = true; 
		for (int i = 1; i<=slength; ++i)
			for (int j = 1; j<=plength; j++) {
				if (p[j - 1] == '*')dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j];
				else if (p[j - 1] == '?')dp[i][j] = dp[i - 1][j - 1];
				else dp[i][j] = p[j-1] == s[i-1] ? dp[i - 1][j - 1] : false;
			}
		return dp[slength][plength];
	}
};

int main() {
	cout << Solution::isMatch("aa", "*");
	getchar();
}