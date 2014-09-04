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
	ListNode *partition(ListNode *head, int x) {
		if (NULL == head || NULL == head->next)
			return head;

		ListNode *pRet(NULL), *pNode(head);
		ListNode **pL(&pRet), **pR(&head);
		while (NULL != pNode) {
			if (pNode->val < x) {
				*pL = pNode;
				pL = &((*pL)->next);
			} else {
				*pR = pNode;
				pR = &((*pR)->next);
			}

			pNode = pNode->next;
		}
		*pR = NULL;
		*pL = head;

		return pRet;
	}
};
