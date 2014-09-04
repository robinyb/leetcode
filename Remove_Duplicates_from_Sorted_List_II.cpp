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

		ListNode **pCur(&head);
		ListNode *pNode(head);
		bool bDup(false);

		while (NULL != pNode->next) {
			if (pNode->val == pNode->next->val)
				bDup = true;
			else {
				if (bDup)
					bDup = false;
				else {
					*pCur = pNode;
					pCur = &((*pCur)->next);
				}
			}

			pNode = pNode->next;
		}

		if (bDup)
			*pCur = NULL;
		else
			*pCur = pNode;

		return head;
	}
};
