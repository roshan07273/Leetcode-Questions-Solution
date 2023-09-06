class Solution {
private:
    bool isPalindrome(string &s , int start , int end){
        while(start < end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
private:
    int fun(string &s , int ind , vector<int> &dp){
        if(ind == s.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        int ans = INT_MAX;
        for(int i = ind ; i < s.size() ; i++){
            if(isPalindrome(s , ind , i)){
                int cnt = 1 +  fun(s , i+1 , dp);
                ans = min(ans , cnt);
            }
        }
        return dp[ind] = ans;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n , -1);
        return fun(s , 0 , dp) - 1;
    }
};
