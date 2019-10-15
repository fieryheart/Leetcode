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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
        int left = 0, right = nums.size()-1;
        TreeNode* root = dfs(nums, left, right);
        return root;
    }
    TreeNode* dfs(vector<int>& nums, int left, int right) {
        if(right < left) return NULL;
        int mid = (left+right)/2;
        TreeNode* tmp = new TreeNode(nums[mid]);
        tmp->left = dfs(nums, left, mid-1);
        tmp->right = dfs(nums, mid+1, right);
        return tmp;
    }
};