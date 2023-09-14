class Solution {
private:
    bool find(string s){
        sort(s.begin() , s.end());
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            if(s[i] == s[i+1]) return false;
        }
        return true;
    }
private:
    void helper(int ind , vector<string> &ans , vector<string> &arr , string st , int n){
        if(ind == n && find(st)){
            ans.push_back(st);
            return ;
        }
        if(find(st) == false) return;
        helper(ind + 1 , ans , arr , st + arr[ind] , n);
        
        helper(ind + 1 , ans , arr , st , n);
        
    }
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<string>ans;
        string st = "";
        helper(0 , ans , arr , st , n);
        sort(ans.begin() , ans.end());
        
        int maxi = 0;
        for(int i = 0 ; i < ans.size() ; i++){
            if(ans[i].length() > maxi){
                maxi = ans[i].length();
            }
        }
        return maxi;
    }
};
