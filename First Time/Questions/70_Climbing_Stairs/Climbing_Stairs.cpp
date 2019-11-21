#include <iostream>
#include <queue>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int before_last = 1, last = 2, cnt;
        for(int i = 3; i <= n; ++i) {
            cnt = before_last + last;
            before_last = last;
            last = cnt;
        }
        return cnt;
    }
};
int main()
{
    int n = 6;
    Solution s;
    int rst = s.climbStairs(n);
    cout << rst << endl;
    return 0;
}