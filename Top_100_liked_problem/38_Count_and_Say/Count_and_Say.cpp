class Solution {
public:
    string countAndSay(int n) {
        if(n < 1) return "";
        if(n == 1) return "1";
        string say = "1";
        while(--n) {
            string temp = "";
            for(int i = 0;i < say.size(); ++i) {
                int cnt = 1;
                while(i+1 < say.size() && say[i] == say[i+1]) {
                    cnt++;
                    i++;
                }
                temp += to_string(cnt) + say[i];
            }
            say = temp;
        }
        return say;
    }
};