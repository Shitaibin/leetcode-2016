class Solution {
    enum OPERATION {BUY, SELL};
    
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        
        int n = prices.size();
        
        OPERATION op = BUY;
        int profit = 0;
        int val = 0;
        for (int i = 0; i < n; i++) {
            if (op == BUY) {
                if (i < n-1 && prices[i] < prices[i+1]) {
                    val = prices[i]; // go up, buy it
                    op = SELL;
                }
            } else {
                if (i < n-1 && prices[i] > prices[i+1]) {
                    profit += (prices[i]-val); // go down, sell it
                    op = BUY;
                }
            }
        }
        // wait to sell
        if (op == SELL) {
            profit += prices[n-1]-val;
        }
        
        return profit;
    }
};