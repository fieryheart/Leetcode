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
    int diameterOfBinaryTree(TreeNode* root) {
        vector<TreeNode*> longestPathFromRoot, longestPathFromNode, path;
        map<TreeNode*, bool> mapp;
        int diameter = 0, pathLengthFromRoot = 0, pathLengthFromNode = 0;
        findLongestPath(root, longestPathFromRoot, path);
        for(auto node : longestPathFromRoot) mapp[node] = true;
        diameter = pathLengthFromRoot = longestPathFromRoot.size();
        for(int i = 0; i < pathLengthFromRoot; ++i) {
            TreeNode* node = longestPathFromRoot[i];
            if(node->left && node->right) {
                path.clear();
                longestPathFromNode.clear();
                mapp[node->left] ? findLongestPath(node->right, longestPathFromNode, path)
                                 : findLongestPath(node->left, longestPathFromNode, path);
                pathLengthFromNode = (int)longestPathFromNode.size();
                if(pathLengthFromNode + pathLengthFromRoot - i> diameter)
                    diameter = pathLengthFromNode + pathLengthFromRoot - i; 
            }             
        }
        return diameter ? diameter - 1 : 0;
    }
    void findLongestPath(TreeNode* root, vector<TreeNode*> &longestPath, vector<TreeNode*> &path) {
        if(!root) {
            if((int)path.size() > (int)longestPath.size())
                longestPath = path;
        } else {
            path.push_back(root);
            findLongestPath(root->left, longestPath, path);
            findLongestPath(root->right, longestPath, path);
            path.pop_back();
        }
    }
};