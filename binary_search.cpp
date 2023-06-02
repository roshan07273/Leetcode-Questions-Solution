class Solution {
  public:
    int binarysearch(int arr[], int n, int x) {
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(x == arr[mid])
            {
                 return mid;
            }else if(x > arr[mid])
            {
                low = mid+1;
            }else
            {
               high = mid-1;
            }
           
        }      
        return -1; 
    }
};
