class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int c = 0, d = 0;
        for(int i=0;i<n/2;i++){
            if(s[i] == 'A' || s[i] == 'a' || s[i] == 'E' || s[i] == 'e' || s[i] == 'I' || s[i] == 'i' || s[i] == 'O' || s[i] == 'o' || s[i] == 'U' || s[i] == 'u') c++;
        }
        for(int i=n/2;i<n;i++){
            if(s[i] == 'A' || s[i] == 'a' || s[i] == 'E' || s[i] == 'e' || s[i] == 'I' || s[i] == 'i' || s[i] == 'O' || s[i] == 'o' || s[i] == 'U' || s[i] == 'u') d++;
        }
        if(c == d) return true;
        return false;
    }
};