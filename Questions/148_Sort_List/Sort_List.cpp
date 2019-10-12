#include <iostream>
#include <vector>
#include "../../Utils/Utils.h"
using namespace std;

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int block = 1, list_length = 0;
        ListNode* origin = new ListNode(0);
        origin->next = head;
        ListNode *tmp = head;
        while(tmp) {
            list_length++;
            tmp = tmp->next;
        }
        while(block < list_length) {
            int cur = 0;
            ListNode* cur_needle = origin;
            tmp = origin->next;
            while(cur < list_length) {
                int l1_block = 0, l2_block = 0;
                l1_block = min(list_length-cur, block);
                l2_block = min(list_length-cur-l1_block, block);

                ListNode *l1, *l2;
                l1 = tmp;
                if(l2_block != 0) {
                    for(int i = 0; i < l1_block-1; ++i) tmp = tmp->next;
                    l2 = tmp->next;
                    tmp->next = NULL;
                    
                    tmp = l2;
                    for(int i = 0; i < l2_block-1; ++i) tmp = tmp->next;
                    ListNode* temp = tmp->next;
                    tmp->next = NULL;
                    tmp = temp;
                }

                while(l1 || l2) {
                    if(l2 == NULL || (l1 != NULL && l1->val <= l2->val)) {
                        cur_needle->next = l1;
                        cur_needle = cur_needle->next;
                        l1 = l1->next;
                    } else {
                        cur_needle->next = l2;
                        cur_needle = cur_needle->next;
                        l2 = l2->next;
                    }
                }
                cur_needle->next = NULL;
                cur += l1_block + l2_block;
            }
            block *= 2;
        }
        return origin->next;
    }
};


int main()
{
    vector<int> nums = {4,2,1,3};
    ListNode* list = CreateList(nums);
    Solution s;
    ListNode* temp = s.sortList(list);
    while(temp) {
        cout << temp->val;
        if(temp->next) cout << "->";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}