/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //中间冷冻期有一天
        //可以有多次交易，但是不能同时多次交易
        for(int i=0;i<prices.size();i++)
        {
            
        }
    }
};*/
//动态规划好难，好好理解一下这个过程。。。
class Solution {
public:
    /**
     * @param prices: a list of integers
     * @return: return a integer
     */
    int dp[10001][2];
    int maxProfit(vector<int> &prices) {
        // write your code here
        int len = (int) prices.size();
        if(len == 0) return 0;
        memset(dp,0,sizeof dp);
        // for(int i=0;i<len;i++) dp[i][2] = INT_MIN,dp[i][1] = INT_MIN;
        dp[0][0] = -prices[0]; //0 为买 1 为卖 2 为冷冻 3 为不买也不卖
        dp[0][1] = -1e9; 
        for(int i = 1;i<len;i++){ // 在i处进行买卖
            dp[i][0] = -prices[i];
            for(int j=0;j<i;j++){ // 枚举在何处买入的
                dp[i][1] = max(dp[i][1],dp[j][0] + prices[i]);
            }
            for(int j=0;j<i-1;j++){ // 在何处卖的
                dp[i][0] = max(dp[i][0],dp[j][1] - prices[i]);
            }
            //dp[i][2] = dp[i-1][1];
            //dp[i][3] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        }
        int ans = 0;
        for(int i = 0;i<len;i++){
            ans = max(ans,max(dp[i][0],dp[i][1]));
        }
        return ans;
    }
};