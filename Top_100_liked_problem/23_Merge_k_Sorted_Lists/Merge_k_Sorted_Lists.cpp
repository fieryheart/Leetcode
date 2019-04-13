#include <iostream>
#include <vector>
#include <algorithm>
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *rst = NULL;
        if(lists.size() < 10000){
            for(int i = 0; i < lists.size(); ++i)
            {
                rst = this->mergeTwoLists(rst, lists[i]);
            }
        } else {
            vector<int> temp;
            for(int i = 0; i < lists.size(); ++i)
            {
                while(lists[i]) {
                    temp.push_back(lists[i]->val);
                    lists[i] = lists[i]->next;
                }
            }
            sort(temp.begin(), temp.end());
            rst = this->createList(temp);
        }

        return rst;
    }
};
int main()
{
    vector<vector<int>> nums = {{1, 4, 5},
                                  {1, 3, 4},
                                  {2, 6}};
    vector<ListNode*> lists;
    for(int i = 0; i < nums.size(); ++i)
    {
        lists.push_back(createList(nums[i]));
    }
    Solution s;
    ListNode *rst = s.mergeKLists(lists);
    while(rst) {
        cout << rst->val;
        if(rst->next) cout << "->";
        rst = rst->next;
    }
    cout << endl;
    return 0;
}