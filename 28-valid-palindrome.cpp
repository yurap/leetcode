// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isAlphaNum(char c) {
        return
            (c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9');
    }
    
    char lower(char c) {
        if (c >= 'A' && c <= 'Z') c = 'a' + (c - 'A');
        return c;
    }
       
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < s.size() && !isAlphaNum(s[i])) ++i;
            while (j >= 0 && !isAlphaNum(s[j])) --j;
            
            if (i >= j) return true;
            if (lower(s[i]) != lower(s[j])) return false;
            ++i; --j;
        }
        return true;
    }
};
