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
    ListNode *l = NULL, *last = NULL;
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
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
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
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        ListNode *rst = NULL, *l1_temp = l1, *l2_temp = l2, *l1_last, *l2_last;
        int carry = 0, l1_count = 0, l2_count = 0, x, y, sum;
        while(l1_temp || l2_temp) {
            x = l1_temp ? l1_temp->val : 0;
            y = l2_temp ? l2_temp->val : 0;
            sum = (x+y+carry) % 10;
            carry = (x+y+carry) / 10;
            if(l1_temp) {
                l1_temp->val = sum;
                l1_last = l1_temp;
                l1_temp = l1_temp->next;
                l1_count++;
            }
            if(l2_temp) {
                l2_temp->val = sum;
                l2_last = l2_temp;
                l2_temp = l2_temp->next;
                l2_count++;
            }
        }
        if(carry) {
            if(l1_count < l2_count) l2_last->next = new ListNode(carry);
            else l1_last->next = new ListNode(carry);
        }
        rst = l1_count < l2_count ? l2 : l1;
        return rst;
    }
};

int main()
{
    vector<int> v1 = {1};
    vector<int> v2 = {9,9,9,9};
    ListNode *l1 = createList(v1);
    ListNode *l2 = createList(v2);
    Solution s;
    ListNode* l = s.addTwoNumbers2(l1, l2);
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