#include <iostream>
using std::cout;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *result = new ListNode(0),*head = result;
		int carry = 0;
		while (l1!=NULL || l2!=NULL || carry) {
			int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
			carry = sum / 10;
			sum = sum % 10;
			result->next = new ListNode(sum);
			result = result->next;
			l1 = l1 ? l1->next : l1;
			l2 = l2 ? l2->next : l2;
		}
		return head->next;
	}

};

int main() {
	ListNode a(9), b(8), *c;
	c = Solution::addTwoNumbers(&a, &b);
	cout << c->val << " " << c->next->val;
}