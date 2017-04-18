//#include <set>
#include <list>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
	
public:

	static int lengthOfLongestSubstring(string s) {
		//set<char> record;
		//int max_length = 0, cur_length = 0;
		//for (int i = 0; i < s.length(); i++) {
		//	if(!record.count(s[i])){
		//		record.insert(s[i]);
		//		cur_length++;
		//	}
		//	else {
		//		record.clear();
		//		record.insert(s[i]);
		//		max_length = (cur_length > max_length) ? cur_length : max_length;
		//		cur_length = 1;
		//	}
		//}
		//max_length = (cur_length > max_length) ? cur_length : max_length;
		//return max_length;
		list<char> record;
		int max_length = 0, cur_length = 0;
		for (int i = 0; i < s.length(); ++i) {
			list<char>::iterator it = find(record.begin(), record.end(), s[i]);
			if (it == record.end()) {//don't find repeat
				record.push_back(s[i]);
				cur_length++;

			}
			else {//find
				max_length = (cur_length > max_length) ? cur_length : max_length;
				for (list<char>::iterator it2 = record.begin(); *it2 != *it;) {

					record.erase(it2++);
					cur_length--;
				}
				record.erase(record.begin());
				record.push_back(s[i]);
			}
		}
		max_length = (cur_length > max_length) ? cur_length : max_length;
		return max_length;
	}
};

int main() {
	string a = "dvdf";
	cout << Solution::lengthOfLongestSubstring(a);
}