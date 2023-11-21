class Solution {
private:
    int reverseNum(int num) {
        int reversedNum = 0;
        while (num > 0) {
            reversedNum = reversedNum * 10 + num % 10;
            num /= 10;
        }
        return reversedNum;
    }
    
public:
    int countNicePairs(vector<int>& nums) {
        int cnt = 0;
        unordered_map<int, int> reverseSumCount;

        for (int i = 0; i < nums.size(); i++) {
            int originalNum = nums[i];
            int reversedNum = reverseNum(originalNum);
            int diff = originalNum - reversedNum;

            cnt += reverseSumCount[diff];
            cnt %= 1000000007;

            reverseSumCount[diff]++;
        }

        return cnt;
    }
};
