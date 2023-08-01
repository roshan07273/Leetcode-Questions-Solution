class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int n = nums.size();
        int xo1 = 0;
        int xo2 = 0;
        for(int i = 0 ; i < n ; i++){
            xo2 = xo2 ^ nums[i];
            xo1 = xo1 ^ i;
        }
        xo1 = xo1 ^ n ;
        return xo1 ^ xo2;
    }
};
