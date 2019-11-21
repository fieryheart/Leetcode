/*
 * @Author: fieryheart 
 * @Date: 2019-11-21 14:42:54 
 * @Last Modified by: fiery
 * @Last Modified time: 2019-11-21 14:57:33
 */
#include "../../lib/Root.h"

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

int main()
{
    vector<int> vec1 = {2, 4, 3};
    vector<int> vec2 = {5, 6, 4};
    ListNode* list1 = List::vecToList(vec1);
    ListNode* list2 = List::vecToList(vec2);
    Solution solu;
    ListNode* ans = solu.addTwoNumbers(list1, list2);
    Print::print(ans);
    return 0;
}