#include <iostream>
using namespace std;

/* 请在这里填写答案 */
template<class T>
class MyArray {
    size_t size;
    T *data;
    public:
        MyArray(size_t sz) : size(sz) {
            data = new T[sz];
            // memset(data, 0, sz*sizeof(T));
            for(int i = 0; i < sz; ++i) {
                cin >> data[i];
            }
        }
        void sort();
        bool check();
        void display();
        ~MyArray();
};

template<class T>
void MyArray<T>::sort() {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size-i-1; ++j) {
            if(data[j] > data[j+1]) {
                T temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}

template<class T>
void MyArray<T>::display() {
    for(int i = 0; i < size; ++i) {
        if(i != 0) cout << " ";
        cout << data[i];
    }
    cout << endl;
}

template<class T>
MyArray<T>::~MyArray(){ delete[] data;}

template<class T>
bool MyArray<T>::check(){
    int i;
    for(i=0;i<size-1;i++)
        if(data[i]>data[i+1]) { cout<<"ERROR!"<<endl;return false;}
    return true;
}
int main( )
{
    MyArray<int> *pI;
    MyArray<float> *pF;
    MyArray<char> *pC;
    int ty, size;
    cin>>ty;
    while(ty>0){
        cin>>size;
        switch(ty){
            case 1: pI = new MyArray<int>(size);   pI->sort(); pI->check(); pI->display(); delete pI; break;
            case 2: pF = new MyArray<float>(size); pF->sort(); pF->check(); pF->display(); delete pF; break;
            case 3: pC = new MyArray<char>(size);  pC->sort(); pC->check(); pC->display(); delete pC; break;
        }
        cin>>ty;
    }
    return 0;
}
