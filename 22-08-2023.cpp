class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber > 0){
            columnNumber--;
            char digit = 'A' + (columnNumber % 26);
            ans = digit + ans;
            columnNumber /= 26;
        }
        return ans;
    }
};
