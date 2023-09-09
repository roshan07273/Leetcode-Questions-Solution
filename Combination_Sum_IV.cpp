class Solution {
private:
    int f(int target, vector<int>& nums, vector<int>& dp) {
        if (target < 0) return 0;
        if (target == 0) return 1;
        if (dp[target] != -1) return dp[target];
        
        int ways = 0;
        for (int i = 0; i < nums.size(); i++) {
            ways += f(target - nums[i], nums, dp);
        }
        
        return dp[target] = ways;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        dp[0] = 1;
        return f(target, nums, dp);
    }
};
