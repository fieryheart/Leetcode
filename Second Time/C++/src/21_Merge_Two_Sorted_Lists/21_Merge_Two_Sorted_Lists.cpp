/*
 * @Author: fieryheart 
 * @Date: 2019-12-13 21:43:58 
 * @Last Modified by: fiery
 * @Last Modified time: 2019-12-13 22:07:54
 */
#include "../../lib/Root.h"

//==============================================================

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* head = l1->val <= l2->val ? l1 : l2;
        ListNode* temp = NULL;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                while(l1->next && l1->next->val <= l2->val) l1 = l1->next;
                temp = l1->next;
                l1->next = l2;
                l1 = temp;
            } else {
                while(l2->next && l2->next->val < l1->val) l2 = l2->next;
                temp = l2->next;
                l2->next = l1;
                l2 = temp;
            }
        }
        return head;
    }
};

//==============================================================

int main()
{
    vector<int> list1 = {5};
    vector<int> list2 = {1,3,4};
    ListNode* l1 = List::vecToList(list1);
    ListNode* l2 = List::vecToList(list2);
    Solution solu;
    ListNode* ans = solu.mergeTwoLists(l1, l2);
    Print::print(ans);
    return 0;
}