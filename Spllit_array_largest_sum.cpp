#include<bits/stdc++.h>
class Solution {
public:
    int function(vector<int>& nums , int pages){
        int student = 1;
        int pagesStudent = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(pagesStudent + nums[i] <= pages){
                pagesStudent+=nums[i];
            }else{
                student++;
                pagesStudent = nums[i];
            }
        }
        return student;
    }
public:
    int findPages(vector<int>& nums , int n , int m ){
        if(m > n ) return -1;
        int low = *max_element(nums.begin() , nums.end());
        int high = accumulate(nums.begin() , nums.end() , 0);
        
        while(low <= high){
            int mid = (low + high) >> 1;
            int countStudent = function(nums , mid);
            
            if(countStudent > m) {
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }
        return low;
        
    }
public:
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums , nums.size() , k);
    }
};
