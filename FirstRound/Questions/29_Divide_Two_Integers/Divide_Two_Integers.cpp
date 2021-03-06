class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN) {
            if(divisor == -1) return INT_MAX;
            else if(divisor == 1) return INT_MIN;
            else return divisor&1 ? divide(dividend+1, divisor) : divide(dividend>>1, divisor>>1);
        }
        if(divisor == INT_MIN) return 0;
        int ans = 0, dvd = labs(dividend), dvs = labs(divisor);
        int sign = dividend>0 ^ divisor>0 ? -1 : 1;
        while(dvd >= dvs) {
            int temp = dvs, cnt = 1;
            while(temp<<1 > 0 && temp<<1 <= dvd) {
                temp <<= 1;
                cnt <<= 1;
            }
            dvd -= temp;
            ans += cnt;
        }
        return ans*sign;
    }
};