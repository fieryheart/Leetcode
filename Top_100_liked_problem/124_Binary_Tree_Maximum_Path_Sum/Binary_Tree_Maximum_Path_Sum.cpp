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
    int dfs(TreeNode* root, int &maxn) {
        if(!root) return 0;
        int left = dfs(root->left, maxn);
        int right = dfs(root->right, maxn);
        int val = root->val;
        if(left > 0) val += left;
        if(right > 0) val += right;
        maxn = max(maxn, val);
        return max(root->val, max(left+root->val, right+root->val));
    }
    int maxPathSum(TreeNode* root) {
        int maxn = INT_MIN;
        int val = dfs(root, maxn);
        maxn = max(maxn, val);
        return maxn;
    }
};