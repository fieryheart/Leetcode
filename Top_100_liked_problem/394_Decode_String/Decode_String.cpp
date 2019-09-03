#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct Node {
        string sub;
        int rpt;
        Node *last;
        Node *next;
        Node() : sub(""), rpt(1), last(NULL), next(NULL) {}
    };
    typedef struct Node Node;
    string decodeString(string s) {
        Node* head = new Node();
        Node* tmp = head;
        string num = "";
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '[') {
                Node* nextN = new Node();
                nextN->rpt = stoi(num);
                num = "";
                tmp->next = nextN;
                nextN->last = tmp;
                tmp = nextN;
            } else if(s[i] == ']') {
                string sub = "";
                for(int j = 0; j < tmp->rpt; ++j) sub += tmp->sub;
                tmp = tmp->last;
                tmp->sub += sub;
            } else if(s[i] >= '0' && s[i] <= '9') {
                num += s[i];
            } else {
                tmp->sub += s[i];
            }
        }
        return head->sub;
    }
};

int main()
{
    string s = "3[a2[c]]";
    Solution solu;
    string ans = solu.decodeString(s);
    cout << ans << endl;
    return 0;
}