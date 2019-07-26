// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if (!strs.size()) return result;
        
        int min_len = strs[0].size();
        for (auto& s: strs) {
            if (s.size() < min_len) {
                min_len = s.size();
            }
        }
        
        for (int i = 0; i < min_len; ++i) {
            for (auto& s: strs) {
                if (s[i] != strs[0][i]) {
                    return result;
                }
            }
            result += strs[0][i];
        }
        
        return result;
    }
};
