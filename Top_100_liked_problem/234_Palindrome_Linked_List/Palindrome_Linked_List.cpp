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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode *palin = NULL, *temp1 = head;
        while(temp1) {
            ListNode *temp2 = new ListNode(temp1->val);
            temp2->next = palin;
            palin = temp2;
            temp1 = temp1->next;
        }
        while(palin) {
            if(palin->val != head->val) return false;
            palin = palin->next;
            head = head->next;
        }
        return true;
    }
};