class Solution {
public:
    const int MOD = 1000000007;
    int countOrders(int n) {
        long long len = 2 * n;
        long long ans = 1;
        while (len > 0) {
            long long valid = len * (len - 1) / 2;
            valid %= MOD;
            ans = (ans * valid) % MOD; 
            len = len - 2;
        }
        return ans;
    }
};
