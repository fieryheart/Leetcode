/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        Node* level = root;
        Node* level_cur;
        while(level->left) {
            level_cur = level;
            while(level_cur) {
                level_cur->left->next = level_cur->right;
                if(level_cur->next) level_cur->right->next = level_cur->next->left;
                level_cur = level_cur->next;
            }
            level = level->left;
        }
        return root;
    }
};