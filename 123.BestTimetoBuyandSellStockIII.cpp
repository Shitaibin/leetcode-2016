// 分解成2个子动态规划问题
class Solution {
public:
	// Dynamic Programming
    //
    //     Considering prices[n], and we have a position "i", we could have
    //       1) the maxProfit1 for prices[0..i]  
    //       2) the maxProfit2 for proices[i..n]
    //
    //    So, 
    //      for 1) we can go through the prices[n] forwardly.
    //          forward[i] = max( forward[i-1], price[i] - lowestPrice[0..i] ) 
    //      for 2) we can go through the prices[n] backwoardly.
    //          backward[i] = max( backward[i+1], highestPrice[i..n] - price[i]) 
    //
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        
        int n = prices.size();
        
        vector<int> forward(n);
        forward[0] = 0;
        int lowest_buy_in_price = prices[0];
        for (int i = 1; i < n; i++) {
            forward[i] = max(forward[i-1], prices[i]-lowest_buy_in_price);
            lowest_buy_in_price = min(lowest_buy_in_price, prices[i]);
        }
        
        vector<int> backward(n);
        backward[n-1] = 0;
        int highest_sell_out_price = prices[n-1];
        for (int i = n-2; i >= 0; i--) {
            backward[i] = max(backward[i+1], highest_sell_out_price-prices[i]);
            highest_sell_out_price = max(highest_sell_out_price, prices[i]);
        }
        
        int max_profit = 0;
        for (int i = 0; i < n; i++) {
            max_profit = max(max_profit, forward[i]+backward[i]);
        }
        
        return max_profit;
    }
};