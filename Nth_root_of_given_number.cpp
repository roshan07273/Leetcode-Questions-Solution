class Solution{
public:
    int fun(int mid , int n , int m ) {
        long long ans = 1;
        for(int i = 1; i <= n ; i++){
             ans = ans * mid;
             if(ans > m) return 2;
        }
        if(ans == m) return 1;
        return 0 ;
    }
public:
	int NthRoot(int n, int m)
	{
	   int low = 1;
	   long long high = m;
	   while(low <= high) {
	       long long mid = (low + high) >> 1;
	       int midN = fun(mid , n , m);
	       if(midN == 1) return mid;
	       else if(midN == 0) low = mid + 1;
	       else high = mid - 1;
	   }
	   return -1;
	}  
};
