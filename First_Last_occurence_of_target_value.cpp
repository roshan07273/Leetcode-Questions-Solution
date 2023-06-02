class Solution {
public:
    int lowerBound (vector<int>&nums , int x , int n){
        int low = 0;
        int high = n - 1;
        int ans = n;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] >= x){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
public:
    int upperBound(vector<int>&nums , int x , int n){
        int low = 0;
        int high = n - 1;
        int ans = n;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid ] > x){
                ans = mid;
                high = mid - 1;

            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerBound(nums , target , nums.size());
        int ub = upperBound(nums , target , nums.size() ) -  1;
        if(lb == nums.size() || nums[lb] != target) return {-1 , -1};
        return {lb , ub};
    }
};
