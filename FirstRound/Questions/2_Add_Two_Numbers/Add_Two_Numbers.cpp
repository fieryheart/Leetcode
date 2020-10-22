/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    Note that when the two lists are not the same long , pad the shorter one with zero value, and don't forget to handle the carry value at last.
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        int x, y, z, carry = 0;
        ListNode* head = l1;
        while(true) {
            x = l1->val;
            y = l2->val;
            z = x + y + carry;
            l1->val = z % 10;
            carry = z / 10;
            if(!l1->next && !l2->next) break;
            if(!l1->next) l1->next = new ListNode(0);
            if(!l2->next) l2->next = new ListNode(0);
            l1 = l1->next;
            l2 = l2->next;
        }
        if(carry) l1->next = new ListNode(carry);
        return head;
    }
};