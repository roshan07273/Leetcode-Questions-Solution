class Solution {
private:
    int check(string &s, int p1 , int p2 , int &start , int &end){
        int count = 0;
        if(p1 == p2){
            count++;
            p1--;
            p2++;
        }
        while(p1 >= 0 && p2 < s.length()){
            if(s[p1] != s[p2]){
                start = p1 + 1;
                end = p2 - 1;
                return count;
            }else{
                p1--; 
                p2++;
                count += 2;
            }
        }
        start = p1 + 1;
        end = p2  - 1;
        return count;
        
    }
public:
    string longestPalindrome(string s) {
        int start = -1;
        int end = -1;
        int finalStart = -1;
        int finalEnd = -1;
        int length = 0;
        for(int i = 0 ; i < s.length() ; i++){
            int odd = check(s , i , i , start , end);
            if(odd > length){
                length = odd;
                finalStart = start;
                finalEnd = end;
            }
            int even = check(s , i , i + 1 , start , end);
            if(even > length){
                length = even;
                finalStart = start;
                finalEnd = end;
            }
        }
        return s.substr(finalStart  , finalEnd - finalStart + 1);
    }
};
