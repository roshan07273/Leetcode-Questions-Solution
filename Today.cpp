class Solution {
private:
    int f(int ind , string &s , vector<string>& dictionary , vector<int>&dp , int n){
        if(ind == n) return 0;
        if(dp[ind] != -1 )return dp[ind];
        int ans = n;
        for(string &str : dictionary){
            int strl = str.size();
            if(ind + strl <= s.size() && s.substr(ind , strl) == str){
                int pick = f(ind+strl , s , dictionary , dp , n);
                ans = min(ans , pick);
            }
        }
        
        int notpick = 1 + f(ind+1 , s , dictionary , dp , n );
        ans = min(ans , notpick);
        return dp[ind] = ans;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
    int n = s.size();
    vector<int>dp(n , -1);   
    return f(0 , s , dictionary , dp , n);
    }
};
