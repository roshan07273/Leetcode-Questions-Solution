class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n , -1 );
        stack < int > st;
        for (int i = 0; i < 2 * n; i++) {
            while (!st.empty() && nums[i % n] > nums[st.top()]) {
                nge[st.top()] = nums[i % n];
                st.pop();
            }
            if (i < n) {
                st.push(i); 
            }
        }
        return nge;
    }
};
