#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size(), m = nums2.size();

		int length = m + n;
		vector<int>::iterator it1 = nums1.begin(), it2 = nums2.begin();
		if (length % 2)return findkth(it1,it2, length / 2 + 1,n,m);
		else return (double(findkth(it1, it2, length / 2,n,m)) + findkth(it1, it2, length / 2 + 1,n,m)) / 2;
	}
	static double findkth(vector<int>::iterator& A, vector<int>::iterator& B, int k,int m,int n) {
		
		if (n < m)
			return findkth(B, A,k,n,m);
		if (m == 0)return B[k - 1];
		if (k == 1)return A[0]<B[0] ? A[0] : B[0];
		int pa = k / 2<m ? k / 2 : m;
		int pb = k - pa;
		if (A[pa - 1] == B[pb - 1]) { return A[pa - 1]; }
		if (A[pa - 1] < B[pb - 1]) {
			vector<int>::iterator it1 = A + pa;
			return findkth(it1, B, k - pa, m - pa, n);
		}
			
		else {
			vector<int>::iterator it1 = B + pb;
			return findkth(A, it1, k - pb, m, n - pb);
		}
			
	}

};

int main() {
	vector<int> a = { 1,3}, b = { 2};
	
	
	printf("%lf", Solution::findMedianSortedArrays(a, b));
	getchar();
	return 0;
}