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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root == NULL) return ans;
        TreeNode* last = root;
        vector<int> temp;
        q.push(root);
        while(!q.empty()) {
            TreeNode* w = q.front();
            temp.push_back(w->val);
            q.pop();
            if(w->left) q.push(w->left);
            if(w->right) q.push(w->right);
            if(w == last) {
                ans.push_back(temp);
                temp.clear();
                if(!q.empty()) last = q.back();
            }
        }
        if(temp.size()) ans.push_back(temp);
        return ans;
    }
};