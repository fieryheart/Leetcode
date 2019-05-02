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
    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, int preL, int preR, int inL, int inR) {
        if(preL > preR) return NULL;
        TreeNode* root = new TreeNode(preorder[preL]);
        int idx = inL;
        while(inorder[idx] != preorder[preL]) idx++;
        root->left = createTree(preorder, inorder, preL+1, preL+idx-inL, inL, idx-1);
        root->right = createTree(preorder, inorder, preL+idx-inL+1, preR, idx+1, inR);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return NULL;
        return createTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};