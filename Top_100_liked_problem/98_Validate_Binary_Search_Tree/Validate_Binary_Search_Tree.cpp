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
    void inOrder(vector<int> &ans, TreeNode* root) {
        if(root == NULL) return;
        inOrder(ans, root->left);
        ans.push_back(root->val);
        inOrder(ans, root->right);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        inOrder(ans, root);
        if(ans.size() == 0 || ans.size() == 1) return true;
        for(int i = 1; i < ans.size(); ++i) {
            if(ans[i] <= ans[i-1]) return false;
        }
        return true;
    }
};