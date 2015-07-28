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
        bool isPalindrome(ListNode* head) {
            if (NULL == head || NULL == head->next) return true;
            ListNode* slowNode(head), *fastNode(head);
            while (NULL != fastNode->next && NULL != fastNode->next->next) {
                slowNode = slowNode->next;
                fastNode = fastNode->next->next;
            }
            ListNode* secondHead = reverseList(slowNode->next);
            while (NULL != head && NULL != secondHead) {
                if (head->val != secondHead->val) return false;
                head = head->next;
                secondHead = secondHead->next;
            }
            return true;
        }

        ListNode* reverseList(ListNode* head) {
            if (NULL == head) return NULL;
            ListNode* newHead(head), *tailHead(newHead->next);
            head->next = NULL;
            while (NULL != tailHead) {
                newHead = tailHead;
                tailHead = newHead->next;
                newHead->next = head;
                head = newHead;
            }

            return newHead;
        }
};
