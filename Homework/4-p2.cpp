#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, cnt=1;
    while(cin >> n && n != 0) {
        vector<string> temp(n), ans(n);
        for(int i = 0; i < n; ++i) {
            cin >> temp[i];
        }
        for(int i = 0; i < n; ++i) {
            if((i+1) & 1) ans[i/2] = temp[i];
            else ans[n-1-i/2] = temp[i];
        }
        cout << "SET " << cnt << endl;
        cnt++;
        for(int i = 0; i < n; ++i) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}