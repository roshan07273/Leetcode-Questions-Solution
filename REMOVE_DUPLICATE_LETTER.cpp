class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> feq(26 , 0);
        vector<bool> vis(26 , false);
        
        for(char ch : s){
            feq[ch - 'a']++;
        }
        
        for(char ch : s){
            feq[ch  -  'a']--;
            
            if(vis[ch - 'a']) continue;
            
            while(!st.empty() && ch < st.top() && feq[st.top() - 'a'] > 0){
                vis[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(ch);
            vis[ch - 'a'] = true;
        }
        
        string res = "";
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};
