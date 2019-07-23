class Solution {
public:
    bool isSquare(int n) {
        int i = (int)sqrt(n);
        return i*i == n;
    }
    int numSquares(int n) {
        if(isSquare(n)) return 1;
        while((n & 3) == 0) {
            n >>= 2;
        }
        if((n & 7) == 7) return 4;
        for(int i = 1; i <= (int)sqrt(n); ++i)
            if(isSquare(n-i*i)) return 2;
        return 3;
    }
};