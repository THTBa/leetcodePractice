#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	static string longestPalindrome(string s) {
	//	if (s.empty()) return "";
	//	if (s.size() == 1) return s;
	//	int min_start = 0, max_len = 1;
	//	for (int i = 0; i < s.size();) {
	//		if (s.size() - i <= max_len / 2) break;
	//		int j = i, k = i;
	//		while (k < s.size() - 1 && s[k + 1] == s[k]) ++k; // Skip duplicate characters.
	//		i = k + 1;
	//		while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
	//		int new_len = k - j + 1;
	//		if (new_len > max_len) { min_start = j; max_len = new_len; }
	//	}
	//	return s.substr(min_start, max_len);
	//}

		if (s.length() <= 1)
			return s;
		int count = 0,maxlength = 1,startpos = 0;
		for (int i = 0; i < s.length(); ) {
			int j = i;
			while (j<s.length()&& s[j] == s[j + 1])
				j++;
			int l = i, r = j;
			i = j + 1;
			while (l - 1 >= 0 && r + 1 <= s.length() && s[l - 1] == s[r + 1]) {
				--l; ++r;
			}
			if (r - l + 1 > maxlength) {
				maxlength = r - l + 1;
				startpos = l;
			}
		}
		return s.substr(startpos, maxlength	);
	}
};

int main() {
	string a = "cbbd";
	cout << Solution::longestPalindrome(a);
	getchar();
}