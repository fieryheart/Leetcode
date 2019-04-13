#include <iostream>
#include <vector>
using namespace std;

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
    vector<string> generateParenthesis(int n) {
        vector<string> rst;
        this->dfsParenthesis(rst, "", 0, 0, n);
        return rst;
    }
};

int main()
{
    int n = 0;
    Solution s;
    vector<string> rst = s.generateParenthesis(n);
    for(int i = 0; i < rst.size(); ++i)
        cout << rst[i] << endl;
    return 0;
}