class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int>won;
        vector<int>lost;
        map<int,int>mpp;
        int n = matches.size();
        for(int i=0;i<n;i++) mpp[matches[i][1]]++;
        for(int i=0;i<n;i++){
            if(mpp.find(matches[i][0]) == mpp.end()){
                lost.push_back(matches[i][0]);
                mpp[matches[i][0]]=2;
            }
            if(mpp[matches[i][1]] == 1) won.push_back(matches[i][1]);
        }
        sort(lost.begin(),lost.end());
        sort(won.begin(),won.end());
        return {lost,won};
    }
};