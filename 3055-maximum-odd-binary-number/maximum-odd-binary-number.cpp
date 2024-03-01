class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size(),z=0,o=0;
        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i] == '0') z++;
            else o++;
        }
        if(o>1){
            for(int i=0;i<o-1;i++) ans += '1';
            for(int i=0;i<z;i++) ans += '0';
            ans += '1';
        }
        else{
            for(int i=0;i<z;i++) ans += '0';
            ans += '1';
        }
        return ans;
    }
};