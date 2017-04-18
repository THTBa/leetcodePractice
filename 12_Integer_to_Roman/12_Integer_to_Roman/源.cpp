#include <iostream>
#include <string>
using namespace std;
string romanPieces[35] = { "","I","II","III","IV","V","VI","VII","VIII","IX",
"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
"","M","MM","MMM","MMMM" };
class Solution {
public:
	static string intToRoman(int num) {
		return romanPieces[num / 1000 + 30] + romanPieces[(num / 100) % 10 + 20] + romanPieces[(num / 10) % 10 + 10] + romanPieces[num % 10];
	}
};
//class Solution {
//public:
//	static string intToRoman(int num) {
//		string a;
//		int i = num;
//		for (int j = num / 1000; j > 0; j--) {
//			a.push_back('M');
//		}
//		i = i % 1000;
//		//900 800 400 300
//		if (i >= 900) {
//			i -= 900;
//			a.push_back('C');
//			a.push_back('M');
//		}
//		else if (i >= 500) {
//			i -= 500;
//			a.push_back('D');
//		}
//		else if (i >= 400) {
//			i -= 400;
//			a.push_back('C');
//			a.push_back('D');
//		}
//		for (int j = i / 100; j > 0; j--) {
//			a.push_back('C');
//		}
//
//		i %= 100;
//		if (i >= 90) {
//			i -= 90;
//			a.push_back('X');
//			a.push_back('C');
//		}
//		else if (i >= 50) {
//			i -= 50;
//			a.push_back('L');
//		}
//		else if (i >= 40) {
//			i -= 40;
//			a.push_back('X');
//			a.push_back('L');
//		}
//		for (int j = i / 10; j > 0; j--) {
//			a.push_back('X');
//		}
//
//		i %= 10;
//		if (i >= 9) {
//			i -= 9;
//			a.push_back('I');
//			a.push_back('X');
//		}
//		else if (i >= 5) {
//			i -= 5;
//			a.push_back('V');
//		}
//		else if (i >= 4) {
//			i -= 4;
//			a.push_back('I');
//			a.push_back('V');
//		}
//		for (int j = i; j > 0; j--) {
//			a.push_back('I');
//		}
//		return a;
//	}
//};

int main() {
	int a = 4;
	cout << Solution::intToRoman(a);
	getchar();
}