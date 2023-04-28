class Solution {
public:
bool is_Valid(int x, vector<int>& nums){
        long sum = 0;
    for(int i=0;i<nums.size();i++){
        sum += nums[i];
    if(sum > (long)x * (i+1)) return false;
    }
        return true;
}
    
int minimizeArrayValue(vector<int>& nums) {
        int left = 0, right = *max_element(nums.begin(), nums.end());
    while(left < right){
        int mid = (left + right)/2;
    if(is_Valid(mid, nums))
        right = mid;
    else
        left = mid + 1;
      }
        return left;
    }
};
