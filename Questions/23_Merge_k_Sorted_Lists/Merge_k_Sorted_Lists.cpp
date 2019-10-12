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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val <= l2->val) {
            l1->next = this->mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = this->mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ListNode* mergeKLists1(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        for(int i = 1; i < lists.size(); ++i)
            lists[0] = this->mergeTwoLists(lists[0], lists[i]);
        return lists[0];
    }
    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        ListNode *rst = NULL, *last = NULL;
        vector<ListNode*> lists_temp = lists;
        int minNum = INT_MAX, idx = -1, idx_temp;
        for(int i = 0; i < lists_temp.size(); ++i) {
            if(lists_temp[i] && lists_temp[i]->val < minNum) {
                minNum = lists_temp[i]->val;
                idx = i;
            }
        }
        if(idx != -1) {
            rst = last = lists_temp[idx];
            lists_temp[idx] = lists_temp[idx]->next;
        }
        while(lists_temp.size()) {
            minNum = INT_MAX, idx = -1, idx_temp = -1;
            vector<ListNode*> temp;
            // 这里寻找最小值要换成构建一个最小堆，不然时间复杂度会很大，且不需要temp，此算法实现在mergeKLists3方法
            for(int i = 0; i < lists_temp.size(); ++i) {
                // cout << lists_temp[i] << endl;
                if(lists_temp[i]) {
                    if(lists_temp[i]->val < minNum) {
                        minNum = lists_temp[i]->val;
                        idx = i;
                        idx_temp = temp.size();
                    }
                    temp.push_back(lists_temp[i]);
                }
            }
            // cout << idx << endl;
            if(idx != -1) {
                last->next = lists_temp[idx];
                last = last->next;
                lists_temp[idx_temp] = lists_temp[idx_temp]->next;
            }
        }
        return rst;
    }
    static bool heapComp(ListNode* a, ListNode* b) {
            return a->val > b->val;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) { //make_heap
        ListNode head(0);
        ListNode *curNode = &head;
        vector<ListNode*> v;   
        for(int i =0; i<lists.size(); i++){
            if(lists[i]) v.push_back(lists[i]);
        }
        make_heap(v.begin(), v.end(), heapComp); //vector -> heap data strcture

        while(v.size()>0){
            curNode->next=v.front();
            pop_heap(v.begin(), v.end(), heapComp); 
            v.pop_back(); 
            curNode = curNode->next;
            if(curNode->next) {
                v.push_back(curNode->next); 
                push_heap(v.begin(), v.end(), heapComp);
            }
        }
        return head.next;
    }
};
int main()
{
    vector<vector<int>> nums = {{}};
    vector<ListNode*> lists;
    for(int i = 0; i < nums.size(); ++i)
    {
        lists.push_back(createList(nums[i]));
    }
    Solution s;
    ListNode *rst = s.mergeKLists2(lists);
    while(rst) {
        cout << rst->val;
        if(rst->next) cout << "->";
        rst = rst->next;
    }
    cout << endl;
    return 0;
}