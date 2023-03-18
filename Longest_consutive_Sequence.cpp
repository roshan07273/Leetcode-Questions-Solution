class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int>hashSet;
        for(auto num :nums){
            hashSet.insert(num);
        }
        int longestStreak = 0;
        for(int num : nums){
            if(!hashSet.count(num-1)){
                int currentnum = num;
                int currentstreak = 1;
                
                while(hashSet.count(currentnum+1)){
                    currentnum += 1;
                    currentstreak += 1;
                }
                 longestStreak = max(longestStreak , currentstreak);
            }
        }
        return longestStreak;
        
    }
};
