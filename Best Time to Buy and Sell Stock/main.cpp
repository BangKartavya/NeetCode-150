class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();

            int minBuy = INT_MAX;
            int profit = 0;

            for(int i = 0; i < n; i++) {
                minBuy = min(prices[i], minBuy);

                profit = max(profit, prices[i] - minBuy);
            }

            return profit;
        }
};
