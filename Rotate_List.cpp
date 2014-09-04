/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *rotateRight(ListNode *head, int k) {
		if(NULL == head || 0 >= k)
			return head;

		int iLen(0);
		ListNode *first(head), *second(head);

		while (first) {
			++iLen;
			first = first->next;
		}
		k = k % iLen;

		for (int i(0); i < k; ++i)
			second = second->next;
		first = head;

		for (; NULL != second->next; second = second->next)
			first = first->next;

		second->next = head;
		head = first->next;
		first->next = NULL;

		return head;
	}
};
