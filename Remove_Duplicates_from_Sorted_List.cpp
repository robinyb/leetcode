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
	ListNode *deleteDuplicates(ListNode *head) {
		if (NULL == head || NULL == head->next)
			return head;

		ListNode *pre(head), *cur(pre->next), *tmp(NULL);
		while (NULL != cur) {
			if (pre->val == cur->val)
				tmp = cur;
			else {
				pre->next = cur;
				pre = cur;
			}

			cur = cur->next;
			if (NULL != tmp) {
				delete tmp;
				tmp = NULL;
			}
		}

		pre->next = NULL;

		return head;
	}
};
