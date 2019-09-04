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
    void dfs(TreeNode* root, int &target, int &ans, int sum) {
        sum += root->val;
        if(sum == target) ans++;
        if(root->left) dfs(root->left, target, ans, sum);
        if(root->right) dfs(root->right, target, ans, sum);
        sum -= root->val;
    }
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL) return 0;
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
            dfs(tmp, sum, ans, 0);
        }
        return ans;
    }
};