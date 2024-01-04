class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int cost = prices[0];
        for(int i = 1; i < n; i++){
            int profit = prices[i] - cost;
            ans = max(ans, profit);
            cost = min(cost, prices[i]);
        }
        return ans;
    }
};