class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int>ans;
        for(int i=0;i<=9;i++){
            for(int j=i+1;j<=9;j++){
                int a = stoi(s.substr(i,j-i));
                if(a<=high && a>=low) ans.push_back(a);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};