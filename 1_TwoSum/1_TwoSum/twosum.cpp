class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		map<int,int> m;

		for(int i = 0;i<nums.size();i++){
			m.insert({ nums[i],i });
		}

		for(int i = 1;i<=nums.size();i++){
			int rest = target - m[i];
			map<int, int>::iterator it = m.find(rest);
			if(it->second&&m.find(rest)!=m.end()){
				vector<int> nm ;
				nm.push_back(i);
				nm.push_back(it->second);
				return nm;
			}
		}
    }
};
