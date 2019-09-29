class Solution {
public:
    //简单动态规划方法
    int maxProfit(vector <int>& prices) {
        if(prices.size() <= 1)
            return 0;
        int min = prices[0], max = 0;
        for(int i = 1; i < prices.size(); i++) {
            max = std::max(max, prices[i] - min);
            min = std::min(min, prices[i]);
        }
        return max;
    }
};

