class Solution {
public:
    int ladderLength(string sw, string tw, vector<string>& wl1) {
        unordered_set<string>wl(wl1.begin(), wl1.end()), vis;
        int n = wl.size(), m = sw.size(), ans = 0;
        queue<string>q;
        q.push(sw);
        while(!q.empty()){
            int sz = q.size();
            ans++;
            while(sz--){  
                string wrd = q.front();
                q.pop();
                if(wrd == tw) return ans;
                for(int i=0;i<m;i++){
                    string tmp = wrd;
                    for(char c='a';c<='z';c++){
                        tmp[i] = c;
                        if(wl.count(tmp) && !vis.count(tmp)){
                            q.push(tmp);
                            vis.insert(tmp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};