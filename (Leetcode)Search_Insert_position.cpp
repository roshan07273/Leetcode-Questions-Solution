class Solution {
public:
    int searchInsert(vector<int>& nums,int target) {
        int N = nums.size();
        int start = 0;
        int end = N-1;
        while(start<=end){
        int mid = start+(end-start)/2;
        if(nums[mid]<target){
            start = mid+1;
        }else if(nums[mid]>=target){
            end = mid-1;
        }
    }
    return start;
    }
};
