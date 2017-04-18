#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		char col[9] = { 0 }, row[9] = { 0 }, gro[9] = { 0 };
		vector<int> x, y;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					char k = 1 << (board[i][j] - '0');
					col[j] |= k;
					row[i] |= k;
					gro[(i / 3) * 3 + j / 3] |= k;
				}
				else {
					x.push_back(i);
					y.push_back(j);
				}
			}
		}
		while (x.empty()) {
			for (int i = 0; i < x.size(); i++) {
				char c = col[y[i]] & row[x[i]] & gro[(x[i] / 3) * 3 + y[i] / 3];
				if (!(c | c - 1)) {//if the data is correct,c can not be 0.
					char k = 0;
					while (c != 1) {
						c = c >> 1;
						k++;
					}
					board[x[i]][y[i]] = k + '0';
					char m = (0 - 1) | ~(1 << k);
					col[y[i]] &= m;
					row[x[i]] &= m;
					gro[(x[i] / 3) * 3 + y[i] / 3] &= m;
					x.erase(x.begin() + i);
					y.erase(y.begin() + i);
					i--;
				}
			}
		}
		return;

	}
};


int main() {
	vector<vector<char>> board = ;

}