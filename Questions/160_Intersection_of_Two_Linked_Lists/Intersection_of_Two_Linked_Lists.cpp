/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *inter = NULL;
        stack<ListNode*> stackA, stackB;
        while(headA) {
            stackA.push(headA);
            headA = headA->next;
        }
        while(headB) {
            stackB.push(headB);
            headB = headB->next;
        }
        while(!stackA.empty() && !stackB.empty()) {
            if(stackA.top() == stackB.top()) inter = stackA.top();
            else break;
            stackA.pop();
            stackB.pop();
        }
        return inter;
    }
};