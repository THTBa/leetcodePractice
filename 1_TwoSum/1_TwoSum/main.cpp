#include <map>
#include <array>
#include <iostream>
#include <vector>
using std::vector;
using std::array;
using std::map;
using std::cout;
//template <int t> int* twsm(array<int,t> num,int target){
//	map<int,int> m;
//	for(int i = 0;i<num.size();i++){
//		m.insert({ num[i],i });
//	}
//	for(int i = 1;i<=num.size();i++){
//		int rest = target - m[i];
//		map<int, int>::iterator it = m.find(rest);
//		if(it->second&&m.find(rest)!=m.end()){
//			int *nm = new int[2];
//			nm[0] = i;
//			nm[1] = it->second;
//			return nm;
//		}
//	}
//}

//int main(){
//	int test[] = { 1,3,4,5,4,4 },*num;
//	num = twsm(test, 8);
//	cout << num;
//	delete[] num;
//	return 0;
//}

//int* doubler(int a[], int size)
//{
//	int* temp = new int[size];
//	for (int i = 0; i < size; i++)
//		temp[i] = 2 * a[i];
//	return temp;
//}
//
////µ÷ÓÃ

vector<int> twoSum(vector<int>& nums, int target) {
	map<int, int> m;

	//for (int i = 0; i<nums.size(); i++) {
	//	m[nums[i]] = i;
	//}

	for (int i = 0; i < nums.size(); i++) {
		int rest = target - nums[i];
		map<int, int>::iterator it = m.find(rest);
		if (it != m.end()&&it->second!=i) {
			vector<int> nm;
			nm.push_back(it->second);
			nm.push_back(i); 
			return nm;
		}
		else {
			m[nums[i]] = i;
		}
	}
	
}


int main(){
	vector<int> a{3,2,4};
	vector<int> b;
	b = twoSum(a, 6);
	cout << b[0]<<" "<<b[1];
	getchar(); getchar();
	return 0;
}

