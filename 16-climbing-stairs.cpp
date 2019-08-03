// https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        if (n < 4) return n;

        int prev_prev = 1, prev = 2, res = 3;
        for (int i = 3; i <= n; ++i) {
            res = prev_prev + prev;
            prev_prev = prev;
            prev = res;            
        }
        return res;
    }
};
