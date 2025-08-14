class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        queue<pair<int, int>>q;
        vector<vector<bool>>vis(x+1, vector<bool>(y+1, false));
        q.push({0, 0});
        vis[0][0] = true;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [a, b] = q.front();
                q.pop();
                if((a + b) == target) return true;
                if(!vis[min(a+x, x)][b]){
                    q.push({min(a+x, x), b});
                    vis[min(a+x, x)][b] = true;
                }
                if(!vis[a][min(b+y, y)]){
                    q.push({a, min(b+y, y)});
                    vis[a][min(b+y, y)] = true;
                }
                if(a<x){
                    int t1 = min(a+b, x), t2 = 0;
                    if(t1 == x) t2 = (a+b-x);
                    if(!vis[t1][t2]){
                        q.push({t1, t2});
                        vis[t1][t2] = true;
                    }
                }
                if(b<y){
                    int t1 = min(a+b, y), t2 = 0;
                    if(t1 == y) t2 = (a+b-y);
                    if(!vis[t2][t1]){
                        q.push({t2, t1});
                        vis[t2][t1] = true;
                    }
                }
                if(a>0 && !vis[0][b]){
                    q.push({0, b});
                    vis[0][b] = true;
                }
                if(b>0 && !vis[a][0]){
                    q.push({a, 0});
                    vis[a][0] = true;
                }
            }
        }
        return false;
    }
};