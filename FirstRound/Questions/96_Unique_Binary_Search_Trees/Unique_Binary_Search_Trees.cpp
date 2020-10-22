#include <iostream>
using namespace std;
// 卡特兰数
// C[n+1] = C[0]*C[n] + C[1]*C[n-1] + ... + C[n-1]*C[1] + C[n]*C[0]
// 1...n出栈顺序
class Solution {
public:
    int numTrees(int n) {
        int Catalan[] = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700};
        return Catalan[n];
    }
};
int main()
{
    int n = 18;
    Solution s;
    int rst = s.numTrees(n);
    cout << rst << endl;
    return 0;
}