class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int low = 0 ;
        int high = n - 1;
        int count = 0;
        while(high >= 0 && low < m){
            if(grid[high][low] < 0){
                --high;
                count += m - low;
            }else{
                ++low;
            }
        }
        return count;
    }
};
