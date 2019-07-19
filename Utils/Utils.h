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


// 前缀树结点
struct TrieNode {
    bool isEnd;
    struct TrieNode* child[128];
    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 128; ++i) {
            child[i] = NULL;
        }
    }
};
typedef struct TrieNode TrieNode;



// char To int
int CharToInt(char ch) {
    return ch - ' ' + 32;
}
#endif