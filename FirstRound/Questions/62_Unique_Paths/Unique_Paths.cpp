#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> arr(n, 1);
        for(int i = 1; i < m; ++i) {
            int last = 1;
            for(int j = 1; j < n; ++j) {
                arr[j] += last;
                last = arr[j];
            }
        }
        return arr[n-1];
    }
};
int main()
{
    int m = 1, n = 3;
    Solution s;
    int rst = s.uniquePaths(m, n);
    cout << rst << endl;
    return 0;
}