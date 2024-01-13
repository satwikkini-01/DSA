class Solution {
public:
    int minSteps(std::string s, std::string t) {
        vector<int> c1(26, 0);
        vector<int> c2(26, 0);

        for (char ch : s) c1[ch - 'a']++;
        for (char ch : t) c2[ch - 'a']++;

        int ans = 0;
        for (int i = 0; i < 26; i++) ans += abs(c1[i] - c2[i]);
        return ans / 2;  
    }
};