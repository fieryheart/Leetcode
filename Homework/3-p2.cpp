#include <iostream>
#include <vector>
using namespace std;


template < typename T>
struct  Node
{
    T val;
    struct Node<T>* next;
};

template < typename T>
Node<T>* createNode(T val)//Node<T>* head
{
    Node<T>* node = new Node<T>;
    node->val = val;
    node->next = NULL;
    return node;
}

template < typename T>
void insertNode(Node <T>* head, T val)
{
    Node <T>* p = head;
    while (p->next)
    {
        p = p->next;
    }
    Node<T> *newNode = createNode(val);
    p->next = newNode;
}

template<typename T>
void deleteNode(Node<T>* head,const T x)
{
    Node<T>* pR;
    Node<T>* pN;
    bool flag = false;
    pN = head->next;
    pR = head;
    while (pN)
    {
        if (pN->val == x)
        {
            flag = true;
            pR->next = pN->next;
            delete  pN;
            pN = pR->next; 
            continue;           
        }
        pR = pN;
        pN = pN->next;
    }
    if (!flag)
    {
        cout << "没有这个数字" << endl;
    }
}

template<typename T>
void sort(Node<T>* head)//冒泡排序
{
    Node<T>* pB = head;
    Node<T>* p = pB->next;
    Node<T>* pTail = NULL;
    while(head->next != pTail) {
        pB = head;
        p = pB->next;
        while(p != pTail) {
            if(pB->val > p->val) {
                T temp = pB->val;
                pB->val = p->val;
                p->val = temp;
            }
            pB = p;
            p = p->next;
        }
        pTail = pB;
    }
}

template <typename T>
void displayNode(Node<T>* head)
{
    while (head)
    {
        cout << head->val;
        if(head->next) cout << "\t";
        head = head->next;
    }
    cout << endl;
}

template <typename T>
void deleteSpace(Node<T>* head)
{
    Node<T> *p = head, *pR = NULL;
    while (p != NULL)
    {
        // cout << p << endl;
        pR = p->next;
        delete p;
        p = pR;
        // cout << p << endl;
    }
}

int main()
{
    

    vector<int> v = {20, 12, 0, -5, 9, -18, 6, 11, 5, 3};
    Node<int> *head = createNode(v[0]);
    for(int i = 1; i < v.size(); ++i) {
        insertNode(head, v[i]);
    }
    sort(head);
    displayNode(head);

    cout << "请输入一个要求删除的整数";
    int x;
    cin >> x;
    deleteNode(head, x);
    displayNode(head);


    cout << "请输入一个要求插入的整数";
    cin >> x;
    insertNode(head, x);
    sort(head);
    displayNode(head);

    //删除堆分配
    deleteSpace(head);
    

    return 0;
}