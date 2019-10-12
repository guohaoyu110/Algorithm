//自己写错了，还是看答案吧
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) {
            return 0;
        }
        
        vector<int> profit(prices.size());
        int buy = 0;
        buy = prices[0];
        profit[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            profit[i] = max(profit[i - 1], prices[i] - buy);
            buy = min(buy, prices[i]);
        }
        
        int sell = prices[prices.size() - 1];
        int best = 0;
        for (int i = prices.size() - 2; i >= 0; i--) {
            best = max(best, sell - prices[i] + profit[i]);
            sell = max(sell, prices[i]);
        }
        
        return best;
    }
};

//方法二：
class Solution {
public:
    //最多可以完成两笔交易，最少一笔交易都没有完成
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) {
            return 0;
        }    
        int hold1 = INT_MIN, hold2=INT_MIN;
        int release1=0, release2=0;
        for(int i:prices)
        {
            release2=max(release2,hold2+i);
            hold2 = max(hold2,release1-i); 
            release1 = max(release1, hold1+i);
            hold1 = max(hold1, -i);
        }
        
        return release2;
    }
};