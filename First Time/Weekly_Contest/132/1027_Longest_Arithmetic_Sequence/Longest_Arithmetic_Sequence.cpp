// class Solution {
// public:
//     int longestArithSeqLength(vector<int>& A) {
//         vector< map<int, int> > vmap(A.size());
//         int maxl = 0;
//         for(int i = 0; i < A.size(); ++i) {
//             for(int j = 0; j < i; ++j) {
//                 if(vmap[j][A[i]-A[j]] == 0) vmap[i][A[i]-A[j]] = 2;
//                 else vmap[i][A[i]-A[j]] = vmap[j][A[i]-A[j]]+1;
//                 maxl = max(maxl, vmap[i][A[i]-A[j]]);
//             }
//         }
//         return maxl;
//     }
// };
const int N = 2e3 + 10;
int dp[N][N];

class Solution {
public:
    int longestArithSeqLength(vector<int>& a) {
        int n = a.size();
        map<int, vector<int>> A;
        for (int i = 0; i < n; ++i) {
            A[a[i]].push_back(i);
        }
        int ret = 0;
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = 2;
                int x = a[j] * 2 - a[i];
                if (A.count(x)) {
                    auto it = upper_bound(A[x].begin(), A[x].end(), j);
                    if (it == A[x].end()) continue;
                    int k = *it;
                    dp[i][j] = dp[j][k] + 1;
                }
                ret = max(ret, dp[i][j]);
            }
        }
        return ret;
    }
};