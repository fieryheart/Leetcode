#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class StreamChecker {
public:
    typedef struct Node{
        int maxl;
        map<string, bool> stream;
    }node;
    vector<node> river;
    string s;
    StreamChecker(vector<string>& words) {
        river.resize(30);
        for(int i = 0; i < words.size(); ++i) {
            string str = words[i];
            reverse(str.begin(), str.end());
            river[str[0]-'a'].stream[str] = true;
            if(str.length() > river[str[0]-'a'].maxl)
                river[str[0]-'a'].maxl = str.length();
            // cout << str << " " << river[str[0]-'a'].maxl << endl;
        }
    }
    bool query(char letter) {
        s += letter;
        // cout << "s: " << s << endl;
        for(int i = 1; i <= river[letter-'a'].maxl; ++i) {
            string str = s.substr(s.length()-i);
            // cout << str << endl;
            reverse(str.begin(), str.end());
            // cout << "reverse: " << str << endl;
            if(river[letter-'a'].stream[str]) return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
int main()
{
    vector<string> words = {"cd","f","kl"};
    StreamChecker* streamChecker = new StreamChecker(words);
    string stream = "abcdefghijkl";
    for(int i = 0;i < stream.length(); ++i)
        cout << streamChecker->query(stream[i]) << endl;
    return 0;
}