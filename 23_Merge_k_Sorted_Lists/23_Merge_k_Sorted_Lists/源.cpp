/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include <iostream>
#include <vector> 
#include <queue>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct cmp {
	bool operator()(ListNode *a,ListNode *b) {
		return a->val > b->val;
	}
};
class Solution {
public:
	static ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *res = new ListNode(0), *Node,*Current, *t;
		priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
		for (auto n : lists) {
			if(n)pq.push(n);
		}
		if (pq.empty())return NULL;
		Current = res;
		while(true) {
			t = pq.top();
			Node = new ListNode(t->val);
			Current->next = Node;
			Current = Current->next;
			pq.pop();
			if(t->next)pq.push(t->next);
			if (pq.empty())break;
		}
		t = res->next;
		delete res;
		return t;
	}
};
int main() {
	ListNode *l1 = new ListNode(1), *l2, *l3;
//	ListNode *c1 = l1, *c2 = l2, *c3 = l3;
	//for (int i = 4; i < 10;) {
	//	ListNode *n1 = new ListNode(i++);
	//	c1->next = n1;
	//	c1 = c1->next;
	//	ListNode *n2 = new ListNode(i++);
	//	c2->next = n2;
	//	c2 = c2->next;
	//	ListNode *n3 = new ListNode(i++);
	//	c3->next = n3;
	//	c3 = c3->next;
	//}
	vector<ListNode*> a;
	a.push_back(l1); 
	//a.push_back(l2); a.push_back(l3);
	ListNode *n = Solution::mergeKLists(a);
	while (n) {
		cout << n->val;
		n = n->next;
	}
	getchar();
}