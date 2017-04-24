#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
	static vector<vector<int> > permuteUnique(vector<int> &num) {
		vector<vector<int>> v;
		vector<int> r;
		map<int, int> map;
		for (int i : num)
		{
			if (map.find(i) == map.end()) map[i] = 0;
			map[i]++;
		}
		permuteUnique(v, r, map, num.size());
		return v;
	}

	static void permuteUnique(vector<vector<int>> &v, vector<int> &r, map<int, int> &map, int n)
	{
		if (n <= 0)
		{
			v.push_back(r);
			return;
		}
		for (auto &p : map)
		{
			if (p.second <= 0) continue;
			p.second--;
			r.push_back(p.first);
			permuteUnique(v, r, map, n - 1);
			r.pop_back();
			p.second++;
		}
	}
};


int main() {
	vector<vector<int>> res;
	vector<int> a = { 1,2,3,4 };
	res = Solution::permuteUnique(a);
	for (auto m : res) {
		for (auto n : m) {
			cout << n << ' ';
		}
		cout << endl;
	}
	getchar();
}