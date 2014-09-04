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
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		int iLen(n-m+1);
		if (1 >= iLen)
			return head;

		ListNode **pHead(&head);
		for (int i(1); i < m; ++i)
			pHead = &((*pHead)->next);

		ListNode *pCur(*pHead), *pNxt(NULL), *pPre(NULL);
		while (iLen--) {
			pNxt = pCur->next;
			pCur->next = pPre;
			pPre = pCur;
			pCur = pNxt;
		}
		(*pHead)->next = pCur;
		*pHead = pPre;

		return head;
	}
};
