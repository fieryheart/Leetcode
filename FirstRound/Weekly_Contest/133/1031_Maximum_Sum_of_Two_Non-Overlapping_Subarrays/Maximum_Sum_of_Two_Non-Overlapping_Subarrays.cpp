#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> sum(A.size()+1, 0);
        sum[0] = 0;
        for(int i = 1; i < sum.size(); ++i)
            sum[i] = sum[i-1] + A[i-1];
        int maxm = 0, maxl = 0, ans = 0;
        for(int i = 0; i+M+L < sum.size(); ++i) {
            maxm = max(maxm, sum[i+M]-sum[i]);
            ans = max(ans, maxm+sum[i+M+L]-sum[i+M]);
        }
        for(int i = 0; i+L+M < sum.size(); ++i) {
            maxl = max(maxl, sum[i+L]-sum[i]);
            ans = max(ans, maxl+sum[i+L+M]-sum[i+L]);
        }
        return ans;
    }
};
int main()
{
    vector<int> A = {2,1,5,6,0,9,5,0,3,8};
    int L = 4, M = 3;
    Solution s;
    int rst = s.maxSumTwoNoOverlap(A, L, M);
    cout << rst << endl;
    return 0;
}