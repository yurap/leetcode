// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size()) return 0;
        
        int newBorder = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i-1]) {
                nums[newBorder] = nums[i];
                ++newBorder;
            }
        }
        return newBorder;
    }
};
