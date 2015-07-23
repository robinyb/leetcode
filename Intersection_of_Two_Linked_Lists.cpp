/**
 * Definition for singly-linked list.
 * struct ListNode {
 *      int val;
 *      ListNode *next;
 *      ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            if (NULL == headA || NULL == headB) return NULL;
            int lenA(1), lenB(1);
            ListNode* ptrA(headA), *ptrB(headB);
            while (NULL != ptrA->next) {
                ++lenA;
                ptrA = ptrA->next;
            }
            while (NULL != ptrB->next) {
                ++lenB;
                ptrB = ptrB->next;
            }
            if (ptrA != ptrB) return NULL;
            ptrA = headA;
            ptrB = headB;
            int stepDiff(lenA - lenB);
            if (0 < stepDiff) {
                for (int i(0); i < stepDiff; ++i) ptrA = ptrA->next;
            } else if (0 > stepDiff) {
                for (int i(stepDiff); i < 0; ++i) ptrB = ptrB->next;
            }
            while (ptrA != ptrB) {
                ptrA = ptrA->next;
                ptrB = ptrB->next;
            }
            return ptrA;
        }
};
