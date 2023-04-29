class Solution {
public:
    int fun(int ind , int target , vector<int>&coins , vector<vector<int>>&dp){
        if(ind == 0 ) {
            if(target % coins[0] == 0) return target/coins[0];
            else return 1e9;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int nopick = 0 + fun(ind - 1 , target , coins , dp);
        int pick = 1e9;
        if(target >= coins[ind]) pick = 1 + fun(ind , target-coins[ind] , coins , dp);
        
        return dp[ind][target] = min(pick , nopick);
        
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n , vector<int>(amount+1 , -1));
        int ans = fun(n-1 , amount , coins , dp);
    if(ans >= 1e9) return -1;
    return ans;
        
    }
};
