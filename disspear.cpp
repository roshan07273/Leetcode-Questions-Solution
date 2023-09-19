class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        vector<int> ans;
        for(int num : nums) st.insert(num);
        
        for(int i = 1 ; i <= n ; i++){
            if(st.find(i) == st.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
