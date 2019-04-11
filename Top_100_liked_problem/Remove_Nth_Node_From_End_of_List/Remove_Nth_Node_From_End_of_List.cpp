#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode * createList(vector<int> nums)
{
    ListNode *head, *next;
    for(int i = 0; i < nums.size(); ++i)
    {
        ListNode* temp = new ListNode(nums[i]);
        if(i == 0) head = next = temp;
        else {
            next->next = temp;
            next = temp;
        }
    }
    return head;
}
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode *temp = head, *last = head;
        while(temp) {
            count++;
            temp = temp->next;
        }
        // cout << count << endl;
        int fromBegin = count - n + 1;
        count = 0;
        temp = head;
        while(count < fromBegin-1) {
            count++;
            last = temp;
            temp = temp->next;
        }
        if(temp && last != temp) last->next = temp->next;
        if(last == temp) head = head->next;
        return head;
    }
};

int main()
{
    vector<int> nums = {1,2,3,4,5};
    ListNode* head = createList(nums);
    Solution s;
    ListNode* rst = s.removeNthFromEnd(head, 5);
    while(rst){
        cout << rst->val;
        if(rst->next) cout << "->";
        rst = rst->next;
    }
    return 0;
}