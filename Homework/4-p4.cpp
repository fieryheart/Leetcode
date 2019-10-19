#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
    return a + b > b + a;
}

int main()
{
    unsigned int n(0);
    while (cin >> n)
    {
        string num;
        vector<string> v;
        while (n--)
        {
            cin >> num;
            v.push_back(num);
        }
        sort(v.begin(), v.end(), cmp);
        for (vector<string>::iterator it(v.begin()); it != v.end(); it++)
        {
            cout << *it;
        }
        cout << endl;
    }
    return 0;
}