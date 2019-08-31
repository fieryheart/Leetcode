/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*, int> mapp;
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        if(mapp[root]) return mapp[root];
        int val = 0;
        if(root->left) {
            val += rob(root->left->left) + rob(root->left->right);
        }
        if(root->right) val += rob(root->right->left) + rob(root->right->right);
        val = max(val + root->val, rob(root->left) + rob(root->right));
        mapp[root] = val;
        return val;
    }
};