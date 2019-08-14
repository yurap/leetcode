// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (!prices.size()) return 0;
        
        int current_min = prices[0];
        int max_profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            max_profit = max(max_profit, prices[i] - current_min);
            current_min = min(current_min, prices[i]);
        }
        return max_profit;
    }
};
