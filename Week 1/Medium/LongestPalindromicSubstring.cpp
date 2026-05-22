class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";

        for(int i = 0; i < n; i++){
            // ODD
            int start = i, end = i;
            while((start >= 0 && end < n) && s[start] == s[end]){
                start--;
                end++;
            }
            string tmp = s.substr(start + 1, end - start - 1);
            if(tmp.length() > ans.length()) 
                ans = tmp;
            
            // EVEN
            start = i, end = i+1;
            while((start >= 0 && end < n) && s[start] == s[end]){
                start--;
                end++;
            }
            tmp = s.substr(start + 1, end - start - 1);
            if(tmp.length() > ans.length())
                ans = tmp;
        } 
        return ans;
    }
};
