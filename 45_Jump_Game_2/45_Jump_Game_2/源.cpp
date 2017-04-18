#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//class Solution {
//public:
//	static int jump(vector<int>& nums) {
//		vector<int> dp(nums.size(),0);
//		for (int i = 1; i < nums.size(); i++) {
//			int j = i - 1;
//			while (nums[j] + j < i)j--;
//			dp[i] = dp[j] + 1;
//			for (; j >= 0; j--) {
//				dp[i] = nums[j] + j >= i&&dp[j] + 1 < dp[i] ? dp[j] + 1 : dp[i];
//			}
//		}
//		return dp[nums.size() - 1];
//	}
//};


//BFS ¿í¶ÈÓÅÏÈËÑË÷
class Solution {
public:
	static int jump(vector<int>& nums) {
		int n = nums.size(), step = 0, start = 0, end = 0;
		while (end < n - 1) {
			step++;
			int maxend = end + 1;
			for (int i = start; i <= end; i++) {
				if (i + nums[i] >= n - 1) return step;
				maxend = max(maxend, i + nums[i]);
			}
			start = end + 1;
			end = maxend;
		}
		return step;
	}
};

int main() {
	vector<int> a = { 2,3,1,1,4 };
	cout << Solution::jump(a);
	getchar();
}