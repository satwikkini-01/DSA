class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int i=0;i<n;i++){
            int c = s[i];
            if(c >= 65 && c <= 90){
                c += 32;
                ans += (char)c;
            }
            else if(c >= 97 && c <= 122) ans += (char)c;
            else if(c >= 48 && c <= 57) ans += (char)c;
        }
        n = ans.size();
        for(int i=0;i<n;i++){
            if(ans[i] != ans[n-i-1]) return false;
        }
        return true;
    }
};