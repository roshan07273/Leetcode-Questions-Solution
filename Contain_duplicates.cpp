class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        map<int , int >countDup;;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(countDup[nums[i]]){
                return true;
            }
            countDup[nums[i]]++;
            
        }return false;
        
    }
};
