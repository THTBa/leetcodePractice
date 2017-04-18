#include <iostream>

using namespace std;

class Solution {
public:
	static bool isPalindrome(int x) {
		if (x < 0)return false;
		int ret = 0, a = x;
		while (a) {
			ret = ret * 10 + a % 10;
			a /= 10;
		}
		if (ret == x)return true;
		else return false;
	}
};

int main() {
	int a = -2147447412;
	cout << Solution::isPalindrome(a);
	getchar();
}