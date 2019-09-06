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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL) return t2;
        if(t2 == NULL) return t1;
        dfs(t1, t2);
        return t1;
    }
    void dfs(TreeNode* t1, TreeNode* t2) {
        t1->val += t2->val;
        if(t2->left) {
            if(t1->left == NULL) t1->left = new TreeNode(0);
            dfs(t1->left, t2->left);
        }
        if(t2->right) {
            if(t1->right == NULL) t1->right = new TreeNode(0);
            dfs(t1->right, t2->right);
        }
    }
};