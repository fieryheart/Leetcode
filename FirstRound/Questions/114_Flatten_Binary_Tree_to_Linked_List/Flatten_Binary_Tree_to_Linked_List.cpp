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
    void preOrder(vector<int> &ans, TreeNode* root) {
        if(!root) return ;
        ans.push_back(root->val);
        preOrder(ans, root->left);
        preOrder(ans, root->right);
        root->left = NULL;
        root->right = NULL;
    }
    void flatten(TreeNode* root) {
        vector<int> ans;
        preOrder(ans, root);
        TreeNode* temp = root;
        for(int i = 1; i < ans.size(); ++i) {
            temp->right = new TreeNode(ans[i]);
            temp = temp->right;
        }
    }
};