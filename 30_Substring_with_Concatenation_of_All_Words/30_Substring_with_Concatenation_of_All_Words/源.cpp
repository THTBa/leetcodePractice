#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
	static vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		if (!words.size())return res;
		unordered_map<string,int> umap;
		int length = words[0].size();
		for (vector<string>::iterator it = words.begin(); it != words.end(); ++it) {
			umap[*it] += 1;
		}
		for (int i = 0; i < s.length();i++) {
			unordered_map<string, int> um1(umap);
			for (int j = i; j < s.length(); j += length) {
				unordered_map<string, int>::iterator f = um1.find(s.substr(j, length));
				if (f != um1.end()) {
					if (!(--(f->second)))um1.erase(f);
					if (um1.empty()) {
						res.push_back(i);
						break;
					}
				}
				else break;
			}


			//unordered_map<string, int> um1;
			//for (int j = i; j < s.length(); j += length) {
			//	string str = s.substr(j, length);
			//	unordered_map<string, int>::iterator f = umap.find(str);
			//	if (f != umap.end()) {
			//		um1[str]++;
			//		if (!(--(f->second)))um1.erase(f);
			//		if (um1.empty()) {
			//			res.push_back(i);
			//			break;
			//		}
			//	}
			//	else break;
			//}

		}
		return res;


		//vector<int> ans;
		//int n = s.size(), cnt = words.size();
		//if (n <= 0 || cnt <= 0) return ans;

		//// init word occurence
		//unordered_map<string, int> dict;
		//for (int i = 0; i < cnt; ++i) dict[words[i]]++;

		//// travel all sub string combinations
		//int wl = words[0].size();
		//for (int i = 0; i < wl; ++i) {
		//	int left = i, count = 0;
		//	unordered_map<string, int> tdict;
		//	for (int j = i; j <= n - wl; j += wl) {
		//		string str = s.substr(j, wl);
		//		// a valid word, accumulate results
		//		if (dict.count(str)) {
		//			tdict[str]++;
		//			if (tdict[str] <= dict[str])
		//				count++;
		//			else {
		//				// a more word, advance the window left side possiablly
		//				while (tdict[str] > dict[str]) {
		//					string str1 = s.substr(left, wl);
		//					tdict[str1]--;
		//					if (tdict[str1] < dict[str1]) count--;
		//					left += wl;
		//				}
		//			}
		//			// come to a result
		//			if (count == cnt) {
		//				ans.push_back(left);
		//				// advance one word
		//				tdict[s.substr(left, wl)]--;
		//				count--;
		//				left += wl;
		//			}
		//		}
		//		// not a valid word, reset all vars
		//		else {
		//			tdict.clear();
		//			count = 0;
		//			left = j + wl;
		//		}
		//	}
		//}

		//return ans;
	}
};

int main() {
	string s = "wordgoodgoodgoodbestword";
	vector<string> words = { "word", "good", "best", "good" };
	vector<int> a = Solution::findSubstring(s, words);
	for(vector<int>::iterator it = a.begin();it!=a.end();++it)
		cout << *it<<' ';
	getchar();
}