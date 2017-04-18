#include <iostream>
#include <vector>
using namespace std;
//
//class Solution {
//public:
//	static bool isMatch(string s, string p) {
//		if (p.length() == 0)return false;
//		for (int i = 0, j = 0; i < p.length(); i++) {
//			if (p[i] == '.') {
//				j++;
//				continue;
//			}
//			else if (p[i] == '*') {
//				if (p[i - 1] == '.') {
//					
//					return isMatch(s.substr(j,s.length()-j),p.substr(i+1, s.length() - i - 1));
//				}
//				while (s[j] == p[i-1]) {
//					j++;
//				}
//			}
//			else if (p[i] != s[j++])return false;
//		}
//		return true;
//	}
//};

//Dynamic Programming
class Solution {
public:
	static bool isMatch(string s, string p) {
		int m = s.length(), n = p.length();
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;
		for (int i = 0; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (p[j - 1] != '*')dp[i][j] = i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
				else
					dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 1]&&((s[i - 1] == p[j - 2] || p[j - 2] == '.') && i > 0) && dp[i - 1][j];
		return dp[m][n];
	}
};
int main() {
	string a = "ac", c = "a*c";
	cout << Solution::isMatch(a, c);
	getchar();
}