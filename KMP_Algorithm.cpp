class Solution {
private:
    vector<int> calculateLPS(string &pat){
        int n = pat.size();
        vector<int> lps(n , 0);
        int prev = 0;
        int i = 1;
        while( i < n ){
            if(pat[i] == pat[prev]){
                lps[i] = prev + 1;
                prev++;
                i++;
            }
            else if(prev == 0){
                lps[i] = 0;
                i++;
            }
            else{
                prev = lps[prev - 1];
            }
        }
        return lps;
    }
public:
    int findMatching(string text, string pat) {
        if(pat.empty()) return 0;
        int n = text.size();
        int m = pat.size();
        vector<int> lps = calculateLPS(pat);
        int i = 0;
        int j = 0;
        while(i < n ){
            if(text[i] == pat[i]){
                j++ , i++;
            }else{
                if(j == 0){
                    i++;
                }else{
                    j = lps[j - 1];
                }
            }
            if(j == m) {
                return i - m;
            }
        }
        return -1;
    }
};
