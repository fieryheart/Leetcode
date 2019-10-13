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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        vector<int> temp;
        int depth = 1;
        if(!root) return ans;
        TreeNode* last = root;
        q.push(root);
        while(!q.empty()) {
            TreeNode* tn = q.front();
            q.pop();
            temp.push_back(tn->val);
            if(tn->left) q.push(tn->left);
            if(tn->right) q.push(tn->right);
            if(tn == last) {
                if(!q.empty()) last = q.back();
                if(depth & 1) ans.push_back(temp);
                else {
                    reverse(temp.begin(), temp.end());
                    ans.push_back(temp);
                }
                temp.clear();
                depth++;
            }
        }
        
        return ans;
    }
};