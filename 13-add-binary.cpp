// https://leetcode.com/problems/add-binary

#include <algorithm>

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int carry = 0;
        for (int i = 0; i < max(a.size(), b.size()); ++i) {
            int a_val = 0, b_val = 0;
            
            if (i < a.size() && a[ a.size() - 1 - i ] == '1')
                a_val = 1;

            if (i < b.size() && b[ b.size() - 1 - i ] == '1')
                b_val = 1;
            
            int cur_digit = 0;
            switch (a_val + b_val + carry) {
                case 0: cur_digit = 0; carry = 0; break;
                case 1: cur_digit = 1; carry = 0; break;
                case 2: cur_digit = 0; carry = 1; break;
                case 3: cur_digit = 1; carry = 1; break;
            }
            
            result.push_back('0' + cur_digit);
        }
        if (carry == 1)
            result.push_back('1');
        
        std::reverse(result.begin(), result.end());
        return result;
    }
};
