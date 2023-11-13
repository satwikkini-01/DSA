class Solution {
public:
    bool isVowel(char a){
        if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u' || a=='A' || a=='E' || a=='I' || a=='O' || a=='U') return true;
        return false;
    }

    string sortVowels(string s) {
        int n = s.size();
        vector<char>vowel;
        for(int i=0;i<n;i++) if(isVowel(s[i])) vowel.push_back(s[i]);
        sort(vowel.begin(),vowel.end());
        int j=0;
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                s[i]=vowel[j];
                j++;
            }
        }
        return s;
    }
};