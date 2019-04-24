#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findMaxSubsum(vector<int> A, vector<int>& sum, int l, int r, int len) {
        int max_sum = l == 0 ? sum[len-1] : (sum[l+len-1]-sum[l-1]), left = l, right = r;
        for(int i = l+len; i <= r; ++i)
           if(sum[i]-sum[i-len] > max_sum){
               max_sum = sum[i]-sum[i-len];
               right = i;
               left = i-len+1;
           }
        vector<int> temp = {max_sum, left, right};
        return temp;
    }
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> sum(A.size(), 0);
        sum[0] = A[0];
        for(int i = 1; i < sum.size(); ++i)
            sum[i] = sum[i-1] + A[i];
        vector<int> temp_l = findMaxSubsum(A, sum, 0, A.size()-1, L), temp_m1, temp_m2;
        if(temp_l[1] >= M) temp_m1 = findMaxSubsum(A, sum, 0, temp_l[1]-1, M);
        if(A.size() - temp_l[2] - 1 >= M) temp_m2 = findMaxSubsum(A, sum, temp_l[2]+1, A.size()-1, M);
        int max_sum1 = 0;
        if(temp_m1.size() && temp_m2.size()) {
            max_sum1 = max(temp_l[0] + temp_m1[0], temp_l[0] + temp_m2[0]);
        } else if(temp_m1.size()) {
            max_sum1 = temp_l[0] + temp_m1[0];
        } else if(temp_m2.size()) {
            max_sum1 = temp_l[0] + temp_m2[0];
        }
        

        vector<int> temp_m = findMaxSubsum(A, sum, 0, A.size()-1, M), temp_l1, temp_l2;
        if(temp_m[1] >= L) temp_l1 = findMaxSubsum(A, sum, 0, temp_m[1]-1, L);
        if(A.size() - temp_m[2] - 1 >= L) temp_l2 = findMaxSubsum(A, sum, temp_m[2]+1, A.size()-1, L);
        int max_sum2 = 0;
        if(temp_l1.size() && temp_l2.size()) {
            max_sum2 = max(temp_m[0] + temp_l1[0], temp_m[0] + temp_l2[0]);
        } else if(temp_l1.size()) {
            max_sum1 = temp_l[0] + temp_l1[0];
        } else if(temp_l2.size()) {
            max_sum1 = temp_l[0] + temp_l2[0];
        }


        return max(max_sum1, max_sum2);
    }
};
int main()
{
    vector<int> A = {0,6,5,2,2,5,1,9,4};
    int L = 1, M = 2;
    Solution s;
    int rst = s.maxSumTwoNoOverlap(A, L, M);
    cout << rst << endl;
    return 0;
}