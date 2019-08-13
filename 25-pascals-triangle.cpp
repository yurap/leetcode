// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        
        if (numRows <= 0) return res;
        res.push_back(vector<int>{1});
        
        for (int i = 1; i < numRows; ++i) {
            res.push_back(vector<int>( res[i - 1].size() + 1 ));
            for (int j = 0; j < res[i].size(); ++j) {
                int right_parent = (j + 1 < res[i].size()) ? res[i-1][j] : 0;
                int left_parent = (j > 0) ? res[i-1][j-1] : 0;
                res[i][j] = left_parent + right_parent;
            }
        }
        
        return res;
    }
};
