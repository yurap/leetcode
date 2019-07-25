// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            // invariant:
            // all previous values are in "m" - mapping to indexes
            // gonna check if current value makes a sum with any of them
            auto lookup = m.find(target - nums[i]);
            if (lookup != m.end()) {
                return vector<int> { lookup->second, i };
            }
            
            // just keep the invariant
            m[nums[i]] = i;
        }
        
        // they promised exactly one solution always
        return vector<int>();
    }
};
