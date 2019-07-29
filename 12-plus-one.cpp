// https://leetcode.com/problems/plus-one

#include <algorithm>

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;

        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] + carry == 10) {
                result.push_back(0);
                carry = 1;
            } else {
                result.push_back(digits[i] + carry);
                carry = 0;
            }
        }
        
        if (carry == 1) {
            result.push_back(1);
        }
        
        std::reverse(result.begin(), result.end());
        return result;
    }
};
