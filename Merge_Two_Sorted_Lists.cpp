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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode *ret(NULL);
		ListNode **pCur(&ret);

		while (NULL != l1 && NULL != l2) {
			if (l1->val < l2->val) {
				*pCur = l1;
				l1 = l1->next;
			} else {
				*pCur = l2;
				l2 = l2->next;
			}
			pCur = &((*pCur)->next);
		}

		if (NULL == l1)
			*pCur = l2;
		else
			*pCur = l1;

		return ret;
	}
};
