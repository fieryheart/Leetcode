class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> v = {a,b,c};
        sort(v.begin(), v.end());
        a = v[0];
        b = v[1];
        c = v[2];
        int minm = 0, maxm = 0;
        if(b-a > 2 && c-b > 2) {
            minm = 2;
            maxm = (c-b) + (b-a) - 2;
        } else if(b-a == 1 && c-b == 1) {
            minm = 0;
            maxm = 0;
        } else {
            minm = 1;
            maxm = (c-b) + (b-a) - 2;
        }
        
        return {minm, maxm};
    }
};