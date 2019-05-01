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
    void dfs(vector<int> &ans, TreeNode* root) {
        if(root->left) dfs(ans, root->left);
        ans.push_back(root->val);
        if(root->right) dfs(ans, root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        dfs(ans, root);
        return ans;
    }
};