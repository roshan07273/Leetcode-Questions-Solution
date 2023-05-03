class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n) {
        vector<vector<long long >>dp(n+1 , vector<long long >(2  , 0));
        
        dp[n][0] = dp[n][1] = 0;
        long long  profit = 0;
        for(int ind = n-1 ; ind >= 0 ; ind--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                if(buy){
                    profit = max(-prices[ind] + dp[ind+1][0] , 0 + dp[ind+1][1]);
                    
                }
                else{
                    profit = max(prices[ind] + dp[ind + 1][01] , 0 + dp[ind+1][0]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};
