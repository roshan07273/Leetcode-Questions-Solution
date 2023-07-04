class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
    for (int i = 0; i < 32; ++i) {
        int count = 0;
        for (int num : nums) {
            if ((num >> i) & 1) {
                count++;
            }
        }
        if (count % 3 != 0) {
            result |= (1 << i);
        }
    }
    return result;
    }
};
