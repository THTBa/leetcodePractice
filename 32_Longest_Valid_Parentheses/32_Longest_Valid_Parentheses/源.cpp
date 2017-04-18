#include <stack>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	static int longestValidParentheses(string s) {
		stack<int> st;
		int max = 0,length = s.length();
		for (int i = 0; i < length; i++) {
			if (s[i] == '(') {
				st.push(i);
			}
			else {
				if (!st.empty()&&s[st.top()] == '(')st.pop();
				else st.push(i);
			}
		}
		if (st.empty())return length;
		else {
			int r = length, l;
			while (!st.empty()) {
				l = st.top();
				st.pop();
				max = max > r - l - 1 ? max : r - l - 1;
				r = l;
			}
			max = max > l ? max : l;
		}
		return max;
	}
};

class GrayCode {
public:
	static vector<string> getGray(int n) {
		// write code here
		vector<string> res;
		if (n == 1) {
			res.push_back("0");
			res.push_back("1");
			return res;
		}
		vector<string> getLast(getGray(n - 1));
		for (int i = 0; i<getLast.size(); i++) {
			res.push_back("0" + getLast[i]);
		}
		for (int i = getLast.size()-1; i>=0; i--) {
			res.push_back("1" + getLast[i]);
		}
		return res;
	}
};
int main() {
	vector<string> a(GrayCode::getGray(3));
	for (int i = 0; i < a.size(); i++) {
		cout << a[i]<<' ' <<endl;
	}
	getchar();
	//
	//string t = "())";
	//cout << Solution::longestValidParentheses(t);
	//getchar();
//	string a = "hxKLAGLLzPyTxsFsrUnnSKQBHdQQrOyaEYJRgiJbHIDXFcQkFmIhPNKIBfHxXDBdKAvgZiBLVwnlxJAHmttsSJkZhSmQneNVoKoIYZRjPqsrFFaaqZbyNyeRjVKVFrCGdfycidTqbyQcpAtdRGzzBAaKoqybWMOyhrCQdwcRwQQpQavTnAbjriVwxJOrTYJVGYSWzKYeNAGqBzkJLucabNYvyVFxAGKLfqHXNttaqZfncEdTroGMzZnDbvZBBaRbJvuYIvlWrKaaGrvtyxrsCUOqxdwCrmVEeDrLKZKFJVRmrLsmbmOGUJyfdZIrFhuSwJQGRTYMLxKQNMaCavatlQIRZmFQvyWgQTVENxUcPKQCaUQbjyfaNuwoNdTBNldgrtPUcQodqsuJOdDpUczJWCZaasDdEYJkvituMHrCmZQSlRjIefVisatIUtfxBeKnHPyvWUKzRliFsYWgeXogiEgXDbfxAybwFuqFyEvjfIHEPDPKqEiGUtZhdDIDBGKpvBFyqHeEEhAToAbqHEpIdIhIGBtWjGHiQRctZxQQYkfFoWUbqZyIcjRPQBilHrnqNBzFmoRUYCSrGkawJCcOrMceegISpIpSGVjbngWVMTYtGoAlQFPFyOFAxndJZNfKDTwFIxisKTjyjchidXpYgLfoBOLriuIAHmAbQwoHBgbdUYBHlDQGZJASsHszOEPthLVnYbNqWegmONexfdsTVYHgtDmlyugefOBsqmgNDBoxkkhVHfvrYooVOyxDJQJLjYSngksbTopoPJFsKQzHePLukXyYTYCeW ";
////	cin >> a;
//	int r = 0, l = 0;
//
//	for (auto i : a) {
//		if (i >= 'A'&&i <= 'Z')r++;
//	}
//	r = a.length() - r;
//	for (int k = r; l<k; l++) {
//		if (a[l] >= 'A'&&a[l] <= 'Z') {
//			char c = a[l];
//			a[l] = a[r];
//			a[r] = c;
//			r++;
//		}
//	}
//	cout << a;
//	getchar(); getchar();


}