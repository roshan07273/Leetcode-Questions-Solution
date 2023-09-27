class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        vector<int>ans(2);
        int i = 0;
        int j = m - 1;
        int mini = INT_MAX;
        while(i < n && j >= 0){
            int sum = arr[i] + brr[j];
            
            if(mini > (abs(x - sum))){
                mini = abs(sum - x);
                
                ans[0] = arr[i];
                ans[1] = brr[j];
            }
            if(sum > x) j--;
            else i++;
        }
        return ans;
    }
};
