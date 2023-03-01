class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
         int sum = 0;
        for(auto a:nums) sum+=a ;
        int n = nums.size();
         vector<int>answer(n);
          int leftsum = 0;
          int leftnum = 0;
          for(int i=0;i<n;i++){
            int rightnum  = n-1-leftnum;
            int rightsum = sum-leftsum-nums[i];
            answer[i] =(leftnum*nums[i]-leftsum)+(rightsum-rightnum*nums[i]);
              leftnum++;
              leftsum+=nums[i];
        }
        return answer;
    }
        
    
};
