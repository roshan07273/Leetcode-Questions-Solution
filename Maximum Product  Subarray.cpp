class Solution{
public:
	long long maxProduct(vector<int> nums, int n) {
        long long pre = 1;
        long long suf = 1;
        long long answer = -1e9;
        for(int i = 0 ; i < n;  i++){
            if(pre == 0 ) pre = 1;
            if(suf == 0 ) suf = 1;
            pre = pre * nums[i];
            suf = suf * nums[n - i - 1];
            answer = max(answer , max(pre , suf));
        }
        return answer;
    }
};
