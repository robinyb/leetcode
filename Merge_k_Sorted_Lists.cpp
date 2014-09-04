/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct cmp {
	bool operator()(ListNode* x, ListNode* y) {
		return x->val > y->val;
	}
};

class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		ListNode* ret(NULL);
		ListNode** pCur(&ret);
		priority_queue<ListNode*, vector<ListNode*>, cmp> myQ;

		for (auto l: lists)
			if (l)
				myQ.push(l);

		while (!myQ.empty()) {
			*pCur = myQ.top();
			myQ.pop();
			if ((*pCur)->next)
				myQ.push((*pCur)->next);
			pCur = &((*pCur)->next);
		}

		return ret;
	}
};
