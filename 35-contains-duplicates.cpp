class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> m;
        for (auto v: nums) {
            if (m[v]) return true;
            m[v] = true;
        }
        return false;
    }
};
