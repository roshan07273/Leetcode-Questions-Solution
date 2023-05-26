class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        int maxStart = 0;
        int Start = 0;
        int end = 0;
        unordered_set<char>window;
        while( end < n ){
            if(!window.count(s[end])){
                window.insert(s[end]);
                if(end - Start + 1 > maxLen ){
                    maxLen = end - Start + 1;
                    
                }
                end++;
            }else{
                window.erase(s[Start]);
                Start++;
            }
        }
        return maxLen;
    }
};
