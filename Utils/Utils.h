#ifndef _UTILS_H_
#define _UTILS_H_

#include <vector>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL){}
};
typedef struct Node ListNode;

// 构造链表
ListNode* CreateList(vector<int> nums) {
    if(nums.size() == 0) return NULL;
    ListNode* head = new Node(nums[0]);
    ListNode* temp = head;
    for(int i = 1; i < nums.size(); ++i) {
        temp->next = new Node(nums[i]);
        temp = temp->next;
    }
    return head;
}

#endif