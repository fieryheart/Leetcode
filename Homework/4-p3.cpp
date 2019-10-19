#include <iostream>
using namespace std;
int main()
{
    int ascii[128] = {0};
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); ++i) {
        ascii[s[i]-' ']++;
    }
    bool flag = false;
    int ans = 0;
    for(int i = 0; i < 128; ++i) {
        if(ascii[i]) {
            if(ascii[i] & 1) {
                flag = true;
                ans += ascii[i]-1;
            } else ans += ascii[i];
        }
    }
    if(flag) ans++;
    cout << ans << endl;
    return 0;
}