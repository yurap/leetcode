// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    int length(int x) {
        int res = 0;
        while (x > 0) {
            x /= 10;
            res++;
        }
        return res;
    }
    
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        int i = 0;
        int L = length(x);
        stack<int> s;
        while (x > 0) {
            ++i;
            if (i <= L / 2) {
                s.push(x % 10);
            } else if ((L % 2 == 1) && (i == L / 2 + 1)) {
                1; // pass
            } else {
                if (s.top() != x % 10) return false;
                s.pop();
            }
            
            x /= 10;
        }
        return true;
    }
};
