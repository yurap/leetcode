// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (!nums.size()) return 0;
        int best = nums[0];
        
        int current = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // important case to remember: all values are negative
            current += nums[i];
            best    = max(best, current);
            current = max(current, 0);
        }
        
        return best;
    }
};
