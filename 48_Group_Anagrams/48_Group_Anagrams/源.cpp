#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//	vector<vector<string>> groupAnagrams(vector<string>& strs) {
//		int length = strs.size();
//		vector<vector<string>> res;
//		for (int i = 0; i < length; ++i) {
//			int mnum = findInSets(strs[i]);
//			if (mnum == -1) {
//				addSet(strs[i]);
//				vector<string> vs = { strs[i] };
//				res.push_back(vs);
//			}
//			else {
//				res[mnum].push_back(strs[i]);
//			}
//		}
//		return res;
//	}
//private:
//	vector<unordered_map<char,int>> conts;
//	int findInSets(string &str) {
//		int length = str.length();
//		for (int i = 0; i < conts.size(); ++i) {
//			unordered_map<char, int> ct = conts[i];
//			//if (conts[i].size() != str.length())continue;
//			//int j = 0;
//			//for (; j < str.length(); ++j) {
//			//	if (conts[i].find(str[j]) == conts[i].end())break;
//			//}
//			//if (j == str.length())return i;
//			if (!ct.size() && !length)return i;
//			else if (!ct.size() && length)continue;
//			int j = 0;
//			while (ct.size()&&j<length){
//				if (ct.find(str[j]) == ct.end())break;
//				else {
//					ct[str[j]]--;
//					if (!ct[str[j]])ct.erase(str[j]);
//				}
//				j++;
//			}
//			if (!ct.size()&&j == length)return i;
//		}
//		return -1;
//	}
//	void addSet(string &str) {
//		unordered_map<char,int> us;
//		for (int i = 0; i < str.length(); ++i) {
//			us[str[i]]++;
//		}
//		conts.push_back(us);
//	}
//};


//SOLUTION 2
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, multiset<string>> mp;
		for (string s : strs) {
			string t = s;
			sort(t.begin(), t.end());
			mp[t].insert(s);
		}
		vector<vector<string>> anagrams;
		for (auto m : mp) {
			vector<string> anagram(m.second.begin(), m.second.end());
			anagrams.push_back(anagram);
		}
		return anagrams;
	}
};


//SOLUTION 3 with its own sortway
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, multiset<string>> mp;
		for (string s : strs) {
			string t = strSort(s);
			mp[t].insert(s);
		}
		vector<vector<string>> anagrams;
		for (auto m : mp) {
			vector<string> anagram(m.second.begin(), m.second.end());
			anagrams.push_back(anagram);
		}
		return anagrams;
	}
private:
	string strSort(string& s) {
		int count[26] = { 0 }, n = s.length();
		for (int i = 0; i < n; i++)
			count[s[i] - 'a']++;
		int p = 0;
		string t(n, 'a');
		for (int j = 0; j < 26; j++)
			for (int i = 0; i < count[j]; i++)
				t[p++] += j;
		return t;
	}
};

