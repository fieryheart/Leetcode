#ifndef _UTILS_H_
#define _UTILS_H_

#include <vector>
#include <queue>
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



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
typedef struct TreeNode TreeNode;

TreeNode* createTree(vector<int>& nums, int &n, int i){
    if(i >= n || nums[i] == -1) return NULL;
    TreeNode* node = new TreeNode(nums[i]);
    node->left = createTree(nums, n, i*2+1);
    node->right = createTree(nums, n, i*2+2);
    return node;
}

void levelOrder(TreeNode* root, vector<int> &ans) {
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if(temp) {
            ans.push_back(temp->val);
            q.push(temp->left);
            q.push(temp->right);
        } else ans.push_back(-1);
    }
}
#endif