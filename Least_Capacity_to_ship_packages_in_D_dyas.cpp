class Solution {
public:
    int possible(vector<int>& weights , int capacity){
        int days = 1;
        int load = 0;
        int n = weights.size();
        for(int i = 0 ; i < n ; i++){
            if(load + weights[i] > capacity){
                days = days + 1;
                load = weights[i];
            }else{
                load += weights[i];
            }
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin() , weights.end());
        long long int high =  accumulate(weights.begin() , weights.end() , 0);
        while(low <= high){
            long long int mid = (low + high) >> 1;
            long long daysrequired = possible(weights , mid);
            if(daysrequired <= days){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};
