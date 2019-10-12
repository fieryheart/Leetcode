#include <iostream>
#include <vector>
using namespace std;
typedef struct Node{
    string val;
    int left_number, right_number;
}node;
class Solution {
public:
    // 使用的是dfs，所以内存消耗高，可以改成bfs
    void dfsParenthesis(vector<string> &parenthesis, string str, int b_left_number, int b_right_number, int n)
    {
        if(b_left_number == n && b_right_number == n)
        {
            parenthesis.push_back(str);
            return ;
        }
        if(b_left_number < n) this->dfsParenthesis(parenthesis, str+'(', b_left_number+1, b_right_number, n);
        if(b_right_number < b_left_number) this->dfsParenthesis(parenthesis, str+')', b_left_number, b_right_number+1, n);
    }
    vector<string> generateParenthesis1(int n) {
        vector<string> rst;
        this->dfsParenthesis(rst, "", 0, 0, n);
        return rst;
    }
    vector<string> generateParenthesis2(int n) {
        vector<string> rst;
        vector<node> nodes;
        nodes.push_back({"",0,0});
        for(int i = 0; i < n*2; ++i) {
            vector<node> temp;
            for(int j = 0; j < nodes.size(); ++j)
            {
                if(nodes[j].left_number < n) temp.push_back({nodes[j].val+'(', nodes[j].left_number+1, nodes[j].right_number});
                if(nodes[j].right_number < nodes[j].left_number) temp.push_back({nodes[j].val+')', nodes[j].left_number, nodes[j].right_number+1});
            }
            nodes = temp;
        }
        for(int i = 0; i < nodes.size(); ++i)
            rst.push_back(nodes[i].val);
        return rst;
    }
};

int main()
{
    int n = 3;
    Solution s;
    vector<string> rst = s.generateParenthesis2(n);
    for(int i = 0; i < rst.size(); ++i)
        cout << rst[i] << endl;
    return 0;
}