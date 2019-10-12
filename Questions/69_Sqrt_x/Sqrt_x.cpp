class Solution {
public:
    int mySqrt(int x) {
        int i;
        if(x == 0) return 0;
        for(i = 1; i <= 46340 && i*i <= x; ++i);
        return i-1;
    }
};