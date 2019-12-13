/*
 * @Author: fieryheart 
 * @Date: 2019-12-13 11:17:05 
 * @Last Modified by: fiery
 * @Last Modified time: 2019-12-13 11:35:13
 * @Desc: We can set two points. One points to current position. The other points to n nodes after current. 
 * Then each time we move the two points together. When the front point reach the end, we can remove the next of the back node.
 */
#include "../../lib/Root.h"

//==============================================================

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int tmp = 0;
        ListNode* first = head;
        ListNode* second = head;
        while(first && tmp < n) {
            first = first->next;
            tmp++;
        }
        if(tmp < n) return head;
        if(!first) return head->next;
        while(first->next) {
            first = first->next;
            second = second->next;
        }
        if(second->next) second->next = second->next->next;
        return head;
    }
};

//==============================================================

int main()
{
    Solution solu;
    vector<int> list = {1,2,3,4,5};
    int n = 8;
    ListNode* head = List::vecToList(list);
    ListNode* ans = solu.removeNthFromEnd(head, n);
    Print::print(ans);
    return 0;
}