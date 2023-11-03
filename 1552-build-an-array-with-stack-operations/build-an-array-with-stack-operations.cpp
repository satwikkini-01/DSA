class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int final = target[target.size()-1];
        vector<string>ans;
        stack<int>stk;
        int j=0;
        for(int i=1;i<=final;i++){
            stk.push(i);
            if(stk.top()==target[j]){
                ans.push_back("Push");
                j++;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};