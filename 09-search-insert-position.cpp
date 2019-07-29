// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int begin, int end) {
        // end is not included in the range
        if (begin + 1 == end) {
            if (target <= nums[begin])
                return begin;
            return begin + 1;
        }
        
        int middle = (begin + end) / 2;
        // always true: middle > begin
        // they can be the same only if begin == end + 1
        // which is checked above
        
        if (target == nums[middle])
            return middle;
        else if (target < nums[middle])
            return binarySearch(nums, target, begin, middle);
        return binarySearch(nums, target, middle, end);
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size());
    }
};
