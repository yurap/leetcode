// https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result {1};
        if (rowIndex <= 0) return result;
        
        for (int i = 0; i < rowIndex; ++i) {
            int old_prev = 0, new_prev = 0;
            for (int j = 0; j < result.size(); ++j) {
                new_prev = result[j];
                result[j] += old_prev;
                old_prev = new_prev;
            }
            result.push_back(old_prev);
        }
        
        return result;
    }
};
