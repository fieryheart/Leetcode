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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode *, bool> mapp;
        while(head) {
            if(!mapp[head]) mapp[head] = true;
            else return head;
            head = head->next;
        }
        return NULL;
    }
};