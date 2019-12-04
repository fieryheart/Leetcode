#include <iostream>
#include "DS.h"

using namespace std;

class Print {
    private:
        static void showDesc(string &desc) {
            if(!desc.empty()) {
                cout << desc << " : ";
            }
        }
    public:
        template <class T>
        static void print(vector<T> &items, string desc="") {
            showDesc(desc);
            for(auto item : items) {
                cout << item << " ";
            }
            cout << endl;
        }

        template <class T>
        static void print(vector<vector<T>> &items, string desc=""){
            showDesc(desc);
            for(auto item : items) {
                for(auto t : item) {
                    cout << t << " ";
                }
                cout << endl;
            }
        }

        template <class T>
        static void print(T &val, string desc="") {
            showDesc(desc);
            cout << val << endl;
        }

        static void print(double &val, string desc="") {
            showDesc(desc);
            char fmt[] = "%.2lf\n";
            printf(fmt, val);
        }

        static void print(ListNode* head) {
            while(head) {
                cout << head->val;
                if(head->next) cout << "->";
                head = head->next;
            }
            cout << endl;
        }
};