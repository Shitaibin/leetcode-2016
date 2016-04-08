// 刚开始时，我的钱为0，那么最后剩下的钱，就是我的收益。
// sell[i]: 卖掉i后，我还有的钱。
// buy[i]: 买i后，我还有多钱钱。
// 所以买入第0个后，buy[0] = -prices[0]。
// 卖出第0个后，sell[0] = 0.
// 对于卖有两种，一种是我昨天刚买的，今天卖掉：buy[i-1]+prices[i]。
// 另外一种是，昨天没卖，今天卖掉：sell[i-1]-prices[i-1]+prices[i]。
// 而对于买来讲，也分两种，如果是卖掉买，那我所依赖的是前天：sell[i-2]-prices[i]。
// 另外一种是，昨天没有买，今天买：buy[i-1]+prices[i-1]-prices[i]。

class Solution {
    static const int bufsize = 10000;
    int sell[bufsize], buy[bufsize];
    
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        if (n < 2) {
            return 0;
        }
        
        buy[0] = -prices[0];
        sell[0] = 0;
        int max_sell = 0;
        for (int i = 1; i < n; i++) {
            sell[i] = max(buy[i-1]+prices[i], sell[i-1]-prices[i-1]+prices[i]);
            max_sell = max(max_sell, sell[i]);
            if (1 == i) { // 边界条件，保证i-2有效
                buy[i] = buy[0] + prices[0] - prices[1];
            } else {
                buy[i] = max(sell[i-2]-prices[i], buy[i-1]+prices[i-1]-prices[i]);
            }
        }
        return max_sell;
    }
};