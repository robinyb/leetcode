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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *pLRet(NULL);
		ListNode **ppLRet(&pLRet);
		int iCarry(0);

		while (NULL != l1 && NULL != l2) {
			int iTmp = l1->val + l2->val + iCarry;
			*ppLRet = new ListNode(iTmp%10);
			iCarry = iTmp < 10? 0: 1;
			l1 = l1->next;
			l2 = l2->next;
			ppLRet = &((*ppLRet)->next);
		}

		while (NULL != l1) {
			int iTmp = l1->val + iCarry;
			*ppLRet = new ListNode(iTmp%10);
			iCarry = iTmp < 10? 0: 1;
			l1 = l1->next;
			ppLRet = &((*ppLRet)->next);
		}

		while (NULL != l2) {
			int iTmp = l2->val + iCarry;
			*ppLRet = new ListNode(iTmp%10);
			iCarry = iTmp < 10? 0: 1;
			l2 = l2->next;
			ppLRet = &((*ppLRet)->next);
		}

		if (iCarry)
			*ppLRet = new ListNode(1);

		return pLRet;
	}
};
