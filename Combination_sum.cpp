class Solution {
private:
    void f(int k , int n , int ind , vector<vector<int >> &ans , vector<int>v ){
        if(k == 0 && n == 0) {
            ans.push_back(v);
            return;
        }
        for(int i = ind ; i <= 9 ; i++){
            v.push_back(i);
            f(k - 1 , n - i , i + 1 , ans , v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int >> ans;
        vector<int> v;
        f( k , n , 1 , ans , v );
        return ans;
    }
};
