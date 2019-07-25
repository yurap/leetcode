// https://leetcode.com/problems/reverse-integer/

#include <algorithm>

class Solution {
public:
    // convert: int[+/- 123] -> vector[ 3 2 1 ]     
    vector<int> number_to_digits(int x) {
        vector<int> digits;
        while (x != 0) {
            digits.push_back(abs(x - 10 * (x / 10) ));
            x = x / 10;
        }
        return digits;        
    }
    
    // true if a is less then b
    bool digits_less(vector<int>& a, vector<int>& b) {
        if (a.size() != b.size())
            return a.size() < b.size();
        
        for (int i = a.size() - 1; i >= 0; --i) {
            // cout << a[i] << " vs " << b[i] << "\n";
            if (a[i] != b[i])
                return a[i] < b[i];
        }
        
        // they are equal
        return false;
    }
    
    // convert: vector[ 3 2 1 ] -> int[123]
    // sign is needed so result has correct sign
    // so we don't overflow in case of INT_MIN digits
    int digits_to_number (vector<int>& digits, int sign) {
        int result = 0;
        int mult = 1;
        for (int i = 0; i < digits.size(); ++i) {
            result += (sign > 0 ? 1 : -1) * digits[i] * mult;

            // make sure there is no overflow in mult on last iteration
            if (i + 1 < digits.size()) mult *= 10;
        }
        return result;
    }
    
    int reverse(int x) {
        if (x == 0) return 0;

        auto x_digits = number_to_digits(x);
        std::reverse(x_digits.begin(), x_digits.end());
        
        // check overflow
        auto bound = number_to_digits(x > 0 ? INT_MAX : INT_MIN);

        // x > 0 -> need x_digits <= INT_MAX             
        // x < 0 -> need x_digits <= INT_MIN
        if ( digits_less(bound, x_digits) )
            return 0;

        int result = digits_to_number(x_digits, x);
        return result;
    }
};
