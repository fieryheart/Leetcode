/*
 * @Author: fieryheart 
 * @Date: 2019-12-04 14:12:55 
 * @Last Modified by: fiery
 * @Last Modified time: 2019-12-04 14:58:48
 */
#include "../../lib/Root.h"

//==============================================================

class Solution {
public:
    int myAtoi(string str) {
        // trim many whitespace characters first.
        while(!str.empty() && (str[0] == ' ')) str = str.substr(1);
        if(str.empty()) return 0;
        // Print::print(str, "Trim many whitespace characters first");

        // check whether the first sequence of non-whitespace characters in str is a valid integral number, the plus or the minus sign
        if(!(isdigit(str[0]) || str[0] == '+' || str[0] == '-')) return 0;

        // confirm the sign of the number
        bool sign = true;
        if(str[0] == '-') sign = false;
        if(str[0] == '+' || str[0] == '-') str = str.substr(1);

        // check wheter the number is reasonable
        if(str.empty() || !isdigit(str[0])) return 0;

        // trim many zero characters
        while(!str.empty() && (str[0] == '0')) str = str.substr(1);
        if(str.empty()) return 0;

        // trim redundant non-integer characters in the tail of str.
        int no_integer_idx = 0;
        for(no_integer_idx = 0; no_integer_idx < str.length(); ++no_integer_idx) {
            if(!isdigit(str[no_integer_idx])) break;
        }
        str = str.substr(0, no_integer_idx);
        // Print::print(str, "Trim redundant non-integer characters in the tail of str");  

        // check whether the number goes over the limit
        // the number is more than the max positive number
        if(sign == true && (str.length() > 10 || (str.length() ==  10 && str > "2147483647"))) return INT_MAX;

        // the number is less than the min negative number
        if(sign == false && (str.length() > 10 || (str.length() ==  10 && str > "2147483648"))) return INT_MIN;

        if(sign == true && str == "2147483647") return INT_MAX;
        if(sign == false && str == "2147483648") return INT_MIN;

        // handle the rational number
        int ans = 0;
        for(int i = 0; i < str.length(); ++i) {
            ans *= 10;
            ans += (str[i] - '0');
        }

        // add the sign
        ans = sign ? ans : -ans;
        
        return ans;
    }
};

//==============================================================

int main()
{
    string str = "-000000000000001";
    Solution solu;
    int ans = solu.myAtoi(str);
    Print::print(ans);
    return 0;
}