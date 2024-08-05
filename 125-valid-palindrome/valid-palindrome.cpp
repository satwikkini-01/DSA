class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n-1;
        while(l<r){
            if(isalnum(s[l]) && isalnum(s[r])){
                char a = s[l], b = s[r];
                a = tolower(a);
                b = tolower(b);
                if(a == b){
                    l++;
                    r--;
                }
                else return false;
            }
            else if(isalnum(s[l])) r--;
            else l++;
        }
        return true;
    }
};