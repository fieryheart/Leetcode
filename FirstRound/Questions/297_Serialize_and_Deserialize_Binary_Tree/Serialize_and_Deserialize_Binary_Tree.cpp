/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include <queue>
#include "../../Utils/Utils.h"

using namespace std;

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if(temp) {
                q.push(temp->left);
                q.push(temp->right);
                s += to_string(temp->val) + ",";
            } else {
                s += "#,";
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        string sub = "";
        int i = 0;
        queue<TreeNode*> q, q1;
        while(i < data.size()) {
            if(data[i] == ',') {
                if(sub[0] == '#') {
                    q.push(NULL);
                } else {
                    q.push(new TreeNode(stoi(sub)));
                }
                sub = "";
            } else sub += data[i];
            i++;
        }
        q1.push(q.front());
        TreeNode* root = q.front();
        q.pop();
        while(!q1.empty()) {
            TreeNode* temp = q1.front();
            q1.pop();
            if(!q.empty()) {
                if(q.front()) q1.push(q.front());
                temp->left = q.front();
                q.pop();
            }
            if(!q.empty()) {
                if(q.front()) q1.push(q.front());
                temp->right = q.front();
                q.pop();
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

#include <iostream>
int main()
{
    vector<int> nums = {1,2,3,-1,-1,4,5};
    int n = nums.size();
    TreeNode* root = createTree(nums, n, 0);
    Codec codec;
    cout << codec.serialize(root) << endl;
    TreeNode* temp = codec.deserialize(codec.serialize(root));
    vector<int> ans;
    levelOrder(temp, ans);
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ",";
    }
    cout << endl;
    return 0;
}