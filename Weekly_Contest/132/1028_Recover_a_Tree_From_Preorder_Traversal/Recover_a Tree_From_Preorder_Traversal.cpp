#include <iostream>
#include <stack>
#include <algorithm>
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
class Solution {
public:
    typedef struct TreeNodeItem {
        TreeNode* tn;
        int depth;
    }TreeNodeItem;
    TreeNode* recoverFromPreorder(string S) {
        stack<TreeNodeItem> st;
        int depth = 0;
        for(int i = 0; i < S.length();) {
            if(S[i] != '-') {
                int start = i;
                while(i < S.length() && S[i] != '-') i++;
                string temp = S.substr(start, i-start);
                // cout << temp << " " << depth << endl;
                if(st.empty()) st.push({new TreeNode(stoi(temp)), 0});
                else {
                    while(st.top().depth >= depth) st.pop();
                    TreeNode* child = new TreeNode(stoi(temp));
                    if(st.top().tn->left == NULL) st.top().tn->left = child;
                    else st.top().tn->right = child;
                    st.push({child, depth});
                }
                depth = 0;
            } else {
                depth++;
                i++;
            }
        }
        if(st.empty()) return NULL;
        while(st.top().depth != 0) st.pop();
        return st.top().tn;
    };

    void preOrder(TreeNode* root) {
        if(root == NULL) return;
        preOrder(root->left);
        cout << root->val << " ";
        preOrder(root->right);
    }
};
int main()
{
    string str = "";
    Solution s;
    TreeNode* root = s.recoverFromPreorder(str);
    cout << "preOrder: ";
    s.preOrder(root);
    return 0;
}
