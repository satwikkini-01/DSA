class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size(),count=1;
        char a = num[0];
        vector<string>ans;
        for(int i=1;i<n;i++){
            if(num[i]==a){
                count++;
                if(count==3) ans.push_back(num.substr(i-2,3));
            }
            else{
                a = num[i];
                count = 1;
            }
        }
        if(ans.size()!=0){
            sort(ans.begin(),ans.end());
            return ans[ans.size()-1];
        }
        return "";
    }
};