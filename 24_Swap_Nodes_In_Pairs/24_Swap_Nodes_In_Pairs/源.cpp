/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	static ListNode* swapPairs(ListNode* head) {
		// ListNode *l = NULL;
		// if(head&&head->next){
		//     l = head->next;
		//     if(l->next)
		//         head->next = swapPairs(l->next);
		//     else if(head)head->next = NULL;
		//     l->next = head;
		//     return l;
		// }
		// else return head;


		//2)
		//ListNode *Pre = NULL, *Front, *Behind;
		//if (!head || !head->next) {
		//	return head;
		//}
		//Front = head;
		//Behind = head->next;
		//head = Behind;
		//while (true) {
		//	ListNode *n;
		//	if (Pre)Pre->next = Behind;
		//	n = Behind->next;
		//	Behind->next = Front;
		//	Front->next = n;
		//	Pre = Front;
		//	if (Front->next&&Front->next->next) {
		//		Front = Front->next;
		//		Behind = Front->next;
		//	}
		//	else return head;
		//}

		//3)
		 ListNode **pp = &head, *a, *b;
		 while ((a = *pp) && (b = a->next)) {
		     a->next = b->next;
		     b->next = a;
		     *pp = b;
		     pp = &(a->next);
		 }
		 return head;


	}
	static ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head||k == 1) return head;
		ListNode **pp = &head, **a = (ListNode**)malloc(sizeof(ListNode*)*k);
		while (*pp) {
			a[0] = *pp;
			for (int i = 1; i<k; i++) {
				if (a[i - 1]->next)a[i] = a[i - 1]->next;
				else return head;
			}
			a[0]->next = a[k - 1]->next;
			for (int i = 1; i<k; i++) {
				a[i]->next = a[i - 1];
			}
			*pp = a[k - 1];
			pp = &(a[0]->next);
		}
		return head;
	}
};


int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	//head->next->next = new ListNode(3);
	//head->next->next->next = new ListNode(4);
	Solution::reverseKGroup(head,2);
	printf("%.2f", 0.222222);
	getchar();
}