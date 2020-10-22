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
    ListNode *head = NULL, *next;
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
    // 节省内存，不节省时间
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        vector<int> nums;
        while(l1) {
            nums.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            nums.push_back(l2->val);
            l2 = l2->next;
        }
        sort(nums.begin(), nums.end());
        ListNode* head = NULL;
        if(nums.size()) head = this->createList(nums);
        return head;
    }
    // 节省时间，不节省内存
    ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
        ListNode *head, *temp, *next;
        head = next = temp = NULL;
        while(l1 && l2) {
            if(l1->val < l2->val){
                temp = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                temp = new ListNode(l2->val);
                l2 = l2->next;
            }
            if(!head) head = next = temp;
            else {
                next->next = temp;
                next = temp;
            }
        }
        if(head) {
            if(l1) next->next = l1;
            if(l2) next->next = l2;
        } else {
            head = l1 ? l1 : l2 ? l2 : NULL;
        }
        return head;
    }
};
int main()
{
    vector<int> nums1 = {};
    vector<int> nums2 = {0};
    ListNode *l1 = createList(nums1);
    ListNode *l2 = createList(nums2);
    Solution s;
    ListNode *rst = s.mergeTwoLists2(l1,l2);
    while(rst) {
        cout << rst->val;
        if(rst->next) cout << "->";
        rst = rst->next;
    }
    cout << endl;
    return 0;
}