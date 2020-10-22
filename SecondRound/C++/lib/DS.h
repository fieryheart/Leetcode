/*
 * @Author: fieryheart 
 * @Date: 2019-11-21 14:46:42 
 * @Last Modified by: fiery
 * @Last Modified time: 2019-12-04 18:20:16
 * @Desc: Data Structure
 */
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cctype>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class List {
    public:
        static ListNode* vecToList(vector<int> &vec) {
            if(vec.size() == 0) return NULL;
            ListNode* head = new ListNode(vec[0]);
            ListNode* temp = head;
            for(int i = 1; i < vec.size(); ++i) {
                temp->next = new ListNode(vec[i]);
                temp = temp->next;
            }
            return head;
        }
};