// https://leetcode.com/problems/number-of-1-bits/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int counter = 0;
        while (n != 0) {
            counter += n & 1;
            n >>= 1;
        }
        return counter;
    }
};
