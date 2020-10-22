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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *Last, *This, *Next;
        Last = head;
        This = head->next;
        Next = This->next;
        head->next = NULL;
        while(This) {
            This->next = Last;
            Last = This;
            This = Next;
            if(Next) Next = Next->next;
        }
        return Last;
    }
};