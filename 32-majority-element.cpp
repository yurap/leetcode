// https://leetcode.com/problems/majority-element/
// BUT
// see extremely elegant O(1) memory solution: http://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.html

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counters;
        for (auto v: nums) ++counters[v];
        for (auto p: counters)
            if (p.second > nums.size() / 2)
                return p.first;
        return 0;
    }
};
