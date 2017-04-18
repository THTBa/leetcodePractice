#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	static int maxArea(vector<int>& height) {
		int l = 0, r = height.size() - 1 ,res = 0;
		while (l < r) {
			res = max(res, (r - l)*min(height[l], height[r]));
			if (height[l] < height[r])l++;
			else r--;
		}
		return res;
	}
};

int main() {
	vector<int> h = { 1,3,4,5,4,5,6,7,1 };
	cout << Solution::maxArea(h);
}