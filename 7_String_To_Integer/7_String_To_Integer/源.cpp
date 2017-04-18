#include <iostream>

using namespace std;
class Solution {
public:
	static int myAtoi(string str) {
		if (str.length() == 0)return 0;
		bool na = false;
		int k = 0;
		long long ret = 0;
		while (str[k] < '0' || str[k] > '9') {
			if (str[k] == '-' && (str[k + 1] >= '0'&&str[k + 1] <= '9')) {
				na = true;
				k++;
				break;
			}
			else if (str[k] == '+' && (str[k + 1] >= '0'&&str[k + 1] <= '9')) {
				k++;
				break;
			}
			if (str[k] == ' ') {
				k++;
				continue;
			}
			return 0;
		}
		for (int i = k; i < str.length(); i++) {
			if (str[i] >= '0'&&str[i] <= '9') {
				ret = abs(ret) * 10 + str[i] - '0';
				ret = na ? -ret : ret;
			}
			else break;
			if (ret > INT_MAX) {
				ret = INT_MAX;
				break;
			}
			if (ret < INT_MIN) {
				ret = INT_MIN;
				break;
			}
		}
		return (int)ret;
	}
};
//class Solution {
//public:
//	int myAtoi(string str) {
//		int indicator = 1;
//		long result = 0;
//		int i = str.find_first_not_of(' ');
//		if (str[i] == '-' || str[i] == '+')
//			indicator = (str[i++] == '-') ? -1 : 1;
//		while ('0' <= str[i] && str[i] <= '9')
//		{
//			result = result * 10 + (str[i++] - '0');
//			if (result*indicator >= INT_MAX) return INT_MAX;
//			if (result*indicator <= INT_MIN) return INT_MIN;
//		}
//		return result*indicator;
//	}
//};
int main() {
	string a = "-123";
	cout << Solution::myAtoi(a);
	getchar();
}