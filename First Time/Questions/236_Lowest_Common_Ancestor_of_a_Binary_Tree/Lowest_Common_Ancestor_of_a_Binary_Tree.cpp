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
private:
    vector<TreeNode*> listp;
    vector<TreeNode*> listq;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || (root->left == NULL && root->right == NULL)) return root;
        listp.clear();
        listq.clear();
        vector<TreeNode*> temp;
        dfs(root, temp, p, q);
        TreeNode *ans = NULL;
        for(int i = 0; i < listp.size() && i < listq.size(); ++i) {
            if(listp[i] != listq[i]) break;
            ans = listp[i];
        }
        return ans;
    }
    void dfs(TreeNode* root, vector<TreeNode*> &temp, TreeNode* p, TreeNode* q) {
        if(root == NULL) return;
        temp.push_back(root);
        if(root == p) listp = temp;
        if(root == q) listq = temp;
        dfs(root->left, temp, p, q);
        dfs(root->right, temp, p, q);
        temp.pop_back();
    }
};