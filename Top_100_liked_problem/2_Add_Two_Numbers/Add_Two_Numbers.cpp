#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(vector<int> &v)
{
    ListNode *l, *last;
    for(int i = 0; i < v.size(); i++)
    {
        ListNode* temp = new ListNode(v[i]);
        if(i == 0) {
            l = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }
    return l;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1, v2, v;
        ListNode* rst;
        while(l1) {
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            v2.push_back(l2->val);
            l2 = l2->next;
        }
        for(int i = 0; i < v1.size() || i < v2.size(); ++i) {
            int x = i < v1.size() ? v1[i] : 0;
            int y = i < v2.size() ? v2[i] : 0;
            v.push_back( x+y );
        }
        int carry = 0;
        for(int i = 0; i < v.size(); ++i) {
            v[i] += carry;
            if(v[i] > 9) {
                carry = 1;
                v[i] = v[i] - 10;
            } else {
                carry = 0;
            }
        }
        if(carry > 0) v.push_back(carry);
        rst = createList(v);
        return rst;
    }
};

int main()
{
    vector<int> v1 = {2, 4, 3};
    vector<int> v2 = {5, 6, 4};
    ListNode *l1 = createList(v1);
    ListNode *l2 = createList(v2);
    Solution s;
    ListNode* l = s.addTwoNumbers(l1, l2);
    vector<int> v;
    while(l) {
        v.push_back(l->val);
        l = l->next;
    }
    for(int i = v.size()-1; i >= 0; i-- ) {
        cout << v[i];
    }
    cout << endl;
    return 0;
}