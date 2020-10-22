#include <iostream>
#include "DS.h"

using namespace std;

namespace Print{

void showDesc(string &desc) {
    if(!desc.empty()) {
        cout << desc << " : ";
    }
}

template <typename T>
void print(T item, string desc="") {
    showDesc(desc);
    cout << item << endl;    
}

template <class T>
void print(vector<T> &items, string desc="") {
    showDesc(desc);
    for(auto item : items) {
        cout << item << " ";
    }
    cout << endl;
}

void print(ListNode* head) {
    while(head) {
        cout << head->val;
        if(head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

}