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
	ListNode *swapPairs(ListNode *head) {
		ListNode *ret(NULL);
		ListNode **prefix(&ret);

		while (head && head->next) {
			ListNode *nxt = head->next->next;
			*prefix = head->next;
			head->next->next = head;
			prefix = &(head->next);
			head = nxt;
		}
		*prefix = head;

		return ret;
	}
};
