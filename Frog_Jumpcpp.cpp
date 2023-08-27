class Solution {
private:
    bool fun(int ind , int k , vector<int>& stones , vector<vector<int >>&dp){
        int n = stones.size();
        if(ind == n - 1) return true;
        
                
        bool fl = false;
        if(dp[ind][k] != -1) return dp[ind][k];
        for(int j = ind + 1 ; j < n ; j++ ){
            if(stones[j] > (stones[ind] + k + 1)){
                break;
            } 
            else if(stones[j] == (stones[ind] + k - 1 )){
                fl |= fun(j , k - 1  , stones , dp);
            }
            else if(stones[j] == (stones[ind] + k)){
                fl |= fun(j , k , stones , dp);
                
            }
            else if(stones[j] == (stones[ind] + k + 1)){
                fl |= fun(j , k + 1 , stones , dp);
            }
        }
        dp[ind][k] = fl;
        return fl;
    }
public:
    bool canCross(vector<int>& stones) {
        int n  = stones.size();
        vector<vector<int >> dp(n+2 , vector<int>(4000 , -1));
        return fun(0 , 0 , stones , dp);
    }
};
