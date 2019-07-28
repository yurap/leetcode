// https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // i goes from left to right and seeks occurency of value
        // j goes from right to left and seeks non-occurrency of value
        int i = 0, j = nums.size() - 1;
        
        while (i < nums.size()) {
            while (i < nums.size() && nums[i] != val) ++i;
            while (i < j           && nums[j] == val) --j;

            if (j <= i) return i;
            
            swap(nums[i], nums[j]);
            ++i; --j;
        }
        
        return 0;
    }
};
