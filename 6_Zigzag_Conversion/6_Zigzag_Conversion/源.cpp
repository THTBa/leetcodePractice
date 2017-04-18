#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	static string convert(string s, int numRows) {
		if (numRows <= 1)return s;
		string *a = new string[numRows];
		bool up;
		int row = 0;
		for (int i = 0; i < s.length(); i++) {
			a[row].push_back(s[i]);
			if (row == 0)up = true;
			if (row == numRows - 1)up = false;
			row += up ? 1 : -1;
		}

		s.clear();
		for (int j = 0; j < numRows; ++j)
		{
			s.append(a[j]);
		}

		delete[] a;
		return s;
		//vector<vector<char>> zigzag;
		//int length,l = s.length() / (2 * numRows - 2),j = s.length() % (2 * numRows - 2);
		//length = j > numRows ? j - numRows + 1 : (j == 0 ? 0 : 1);
		//length += l*(numRows-1);
		//for (int i = 0; i < numRows; i++) {
		//	vector<char> line(length,' ');
		//	zigzag.push_back(line);
		//}
		//for (int i = 0, row = 0; i < s.length();) {
		//	for (int j = 0; j < numRows; j++) {
		//		zigzag[j][row] = s[i++];
		//		if (i >= s.length())break;
		//	}
		//	if (i >= s.length())break;
		//	for (int j = numRows - 2; j >= 1; j--) {
		//		zigzag[j][++row] = s[i++];
		//		if (i >= s.length())break;
		//	}
		//	++row;
		//}
		//string a;
		//for (int i = 0; i < numRows;i++) {
		//	for (int j = 0; j < zigzag[i].size(); j++) {
		//		if (zigzag[i][j] != ' ')a += zigzag[i][j];
		//	}
		//}
		//return a;
	}
};

int main() {
	string s = "abcdefghijkl";
	int times = 3;
	cout << Solution::convert(s, times);
	getchar();
}