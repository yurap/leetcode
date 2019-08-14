// https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int v = nums[0];
        for (int i = 1; i < nums.size(); ++i)
            v ^= nums[i];
        return v;
    }
};
