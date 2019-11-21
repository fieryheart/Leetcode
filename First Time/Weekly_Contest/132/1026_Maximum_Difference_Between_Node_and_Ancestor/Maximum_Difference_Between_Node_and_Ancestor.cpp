#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;
TreeNode* createTree(vector<int> &input, int root_idx) {
    if(input[root_idx] == -1) return NULL;
    TreeNode* root = new TreeNode(input[root_idx]);
    if(root_idx*2+1 < input.size()) root->left = createTree(input, root_idx*2+1);
    if(root_idx*2+2 < input.size()) root->right = createTree(input, root_idx*2+2);
    return root;
}
class Solution {
public:
    int min_dfs(TreeNode* root, int &max_diff) {
        if(root->left == NULL && root->right == NULL) return root->val;
        int min_num;
        if(root->left == NULL) min_num = min_dfs(root->right, max_diff);
        else if(root->right == NULL) min_num = min_dfs(root->left, max_diff);
        else min_num = min(min_dfs(root->left, max_diff), min_dfs(root->right, max_diff));
        // cout << root->val << " " << min_num << endl;
        max_diff = max(max_diff, abs(root->val - min_num));
        return min(root->val, min_num);
    }
    int max_dfs(TreeNode* root, int &max_diff) {
        if(root->left == NULL && root->right == NULL) return root->val;
        int max_num;
        if(root->left == NULL) max_num = max_dfs(root->right, max_diff);
        else if(root->right == NULL) max_num = max_dfs(root->left, max_diff);
        else max_num = max(max_dfs(root->left, max_diff), max_dfs(root->right, max_diff));
        // cout << root->val << " " << max_num << endl;
        max_diff = max(max_diff, abs(root->val - max_num));
        return max(root->val, max_num);
    }
    int maxAncestorDiff(TreeNode* root) {
        int max_diff = 0;
        int min_num = min_dfs(root, max_diff);
        // cout << max_diff << endl;
        // cout << "max_dfs: " << endl;
        int max_num = max_dfs(root, max_diff);
        // cout << max_diff << endl;
        return max_diff;
    }
};
int main()
{
    vector<int> input = {2,-1,0,-1,-1,-1,4,-1,-1,-1,-1,-1,-1,-1,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1};
    TreeNode* root = createTree(input, 0);
    Solution s;
    int ans = s.maxAncestorDiff(root);
    cout << "ans: " << ans << endl;
    return 0;
}