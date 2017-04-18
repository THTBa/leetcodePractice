#include <vector>
#include <iostream>


using namespace std;

class Solution {
public:
	static int trap(vector<int>& height) {
		return step(height, 0, height.size() - 1);
	}
private:
	static int step(vector<int>& height, int l, int r) {
		if (r-l < 2)return 0;
		int res = 0, start = 0, size = height.size();
		int i = l, j = r, lv = l, rv = r;
		while (true) {
			if (height[i] < height[j])i++;
			else j--;
			if (i >= j)break;
			lv = height[i] > height[lv] ? i : lv;
			rv = height[j] > height[rv] ? j : rv;
		}
		if (rv - lv < 2)res = 0;
		else {
			int lower = height[lv] > height[rv] ? height[rv] : height[lv];
			for (int i = lv; i <= rv; i++) {
				res += height[i] < lower ? lower - height[i] : 0;
			}
		}
		return res+step(height,l,lv)+step(height,rv,r);
	}
};


int main() {
	vector<int> s = { 5,5,1,7,1,1,5,2,7,6 };
	char c = 255;
	unsigned int a = c;
	//cout << Solution::trap(s);
	cout << a;
	getchar();
}