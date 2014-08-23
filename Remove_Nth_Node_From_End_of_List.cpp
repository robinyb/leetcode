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
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		if (NULL == head)
			return head;

		ListNode dummyHead(0);
		dummyHead.next = head;
		ListNode *fast(&dummyHead), *slow(fast);

		while (n--)
			fast = fast->next;

		while (NULL != fast && NULL != fast->next) {
			slow = slow->next;
			fast = fast->next;
		}

		slow->next = slow->next->next;

		return dummyHead.next;
	}
};
