#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        int sign;
        if(n==0) return 1;
        while(n != 0) {
            double temp = n > 0 ? x : 1/x;
            long exp = 1;
            while(exp <= abs(n/2)) {
                temp = temp*temp;
                exp *= 2;
            }
            n = n > 0 ? n-exp : n+exp;
            // cout << exp << " " << temp << endl;
            ans *= temp;
        }
        
        return ans;
    }
};

int main()
{
    double x = 2.00000;
    int n = 10;
    Solution s;
    double ans = s.myPow(x, n);
    cout << ans << endl;
    return 0;
}